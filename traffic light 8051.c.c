#include<reg51.h>

sbit RED    = P1^0;    // P1.0 = Red LED
sbit YELLOW = P1^1;    // P1.1 = Yellow LED  
sbit GREEN  = P1^2;    // P1.2 = Green LED

void delay()
{
    unsigned int i,j;
    for(i=0; i<800; i++)
        for(j=0; j<120; j++);
}

void main()
{
    while(1)
    {
        // Phase 1: Red ON (3 sec)
        RED = 0; YELLOW = 1; GREEN = 1;  
        delay(); delay(); delay();
        
        // Phase 2: Yellow ON (1 sec)  
        RED = 1; YELLOW = 0; GREEN = 1;
        delay();
        
        // Phase 3: Green ON (3 sec)
        RED = 1; YELLOW = 1; GREEN = 0;
        delay(); delay(); delay();
        
        // All OFF (pause)
        RED = 1; YELLOW = 1; GREEN = 1;
        delay();
    }
}
