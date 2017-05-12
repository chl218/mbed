#include "mbed.h"

Serial uart(USBTX, USBRX);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

DigitalOut  trigger(p21);
InterruptIn echo(p22);

Timer timer;

#define MAX_DISTANCE 300
#define TRIGGER_TIME 10.0
#define WAIT_TIME    0.25

void _rise() {
    timer.reset();
    
    trigger = 1;
    timer.start();
    wait_us(TRIGGER_TIME);
    trigger = 0;     
}
 
void _fall() {
    timer.stop();
    float distance = timer.read_us() / 58;
    distance  = distance > MAX_DISTANCE ? MAX_DISTANCE : distance;
    uart.printf("%3.5f cm\n\r", distance);
    
    _rise();
}

int main() {
 
    echo.rise(&_rise);
    echo.fall(&_fall);
    
    trigger = 1;
    wait_us(TRIGGER_TIME);
    trigger = 0;
 
    while(1) {
        wait(WAIT_TIME);
    }
}