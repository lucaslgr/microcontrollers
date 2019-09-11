#include"config.h"
char a;

void interrupt isr(void)
{
    if (INTCONbits.TMR0IF) 
    {
        TMR0 = 131;
        a++;
        if (a >= 125) //8ms*125 = 1s
        {
            a = 0;
            digitalWrite(_RB5, !digitalRead(_RB5));
        }
        INTCONbits.TMR0IF = 0;
    }
}

void setup(void)
{
    PORTB = 0;
    //Configura TMR0
    T0CONbits.T0CS = 0;
    T0CONbits.PSA = 0;
    T0CONbits.T0PS = 0B110;
    T0CONbits.T08BIT = 1;
    TMR0 = 131;
    INTCONbits.TMR0IF = 0;
    INTCONbits.GIE = 1; //Liga todas as interrupções
    INTCONbits.TMR0IE = 1;
    T0CONbits.TMR0ON = 1;
    //T=0.5us*128*(256-131) = 8ms
}

void loop(void) {
}