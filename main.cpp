#include "mbed.h"
#include "HEPTA_EPS.h"
HEPTA_EPS eps(PA_0,PA_4);
Serial pc(USBTX,USBRX,9600);
int main() {
    int flag = 0; // condition
    float btvol;
    for(int i = 0; i < 100; i++) {
        //Get Battery Voltage
        eps.vol(&btvol);
        pc.printf("BatVol = %.2f [V]\r\n",btvol);
        //Power Saving Mode
        if(btvol <= 3.5) {
            eps.shut_down_regulator();
            flag = 1;
        } else {
            eps.turn_on_regulator();
            flag = 0;
        }
        if(flag == 1) {
            pc.printf("Power saving mode ON\r\n"); 
        }
        wait(1.0);
    }
}
