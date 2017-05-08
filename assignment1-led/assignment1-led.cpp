#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

void led_hex(int i) {
    switch(i) {
        case  0: led1 = 0; led2 = 0; led3 = 0; led4 = 0; break;
        case  1: led1 = 0; led2 = 0; led3 = 0; led4 = 1; break;
        case  2: led1 = 0; led2 = 0; led3 = 1; led4 = 0; break;
        case  3: led1 = 0; led2 = 0; led3 = 1; led4 = 1; break;
        case  4: led1 = 0; led2 = 1; led3 = 0; led4 = 0; break;
        case  5: led1 = 0; led2 = 1; led3 = 0; led4 = 1; break;
        case  6: led1 = 0; led2 = 1; led3 = 1; led4 = 0; break;
        case  7: led1 = 0; led2 = 1; led3 = 1; led4 = 1; break;
        case  8: led1 = 1; led2 = 0; led3 = 0; led4 = 0; break;
        case  9: led1 = 1; led2 = 0; led3 = 0; led4 = 1; break;
        case 10: led1 = 1; led2 = 0; led3 = 1; led4 = 0; break;
        case 11: led1 = 1; led2 = 0; led3 = 1; led4 = 1; break;
        case 12: led1 = 1; led2 = 1; led3 = 0; led4 = 0; break;
        case 13: led1 = 1; led2 = 1; led3 = 0; led4 = 1; break;
        case 14: led1 = 1; led2 = 1; led3 = 1; led4 = 0; break;
        case 15: led1 = 1; led2 = 1; led3 = 1; led4 = 1; break;
        default: led1 = 0; led2 = 0; led3 = 0; led4 = 0; break;
    }   
}

void led_scan(int i) {
    switch(i) {
        case  0: led1 = 0; led2 = 0; led3 = 0; led4 = 1; break;
        case  1: led1 = 0; led2 = 0; led3 = 1; led4 = 0; break;
        case  2: led1 = 0; led2 = 1; led3 = 0; led4 = 0; break;
        case  3: led1 = 1; led2 = 0; led3 = 0; led4 = 0; break;
        default: led1 = 0; led2 = 0; led3 = 0; led4 = 0; break;
    }   
}

int main() {

    int i = 0;
    int d = 1;
    
    while(1) {
        led_scan(i);
        
        i = (i+d) % 4;

        
        if(i == 3 || i == 0) {
            d = -d;
        }
            
        wait(0.50);
    }


}
