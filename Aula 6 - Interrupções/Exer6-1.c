#include"config.h"
char a,b;

void interrupt isr(void) {
    if (INTCONbits.TMR0IF) {
        TMR0 = 131;
        a++;
        if (a >= 125) //8ms*125 = 1s
        {
            a = 0;
            digitalWrite(_RB5, !digitalRead(_RB5));
        }
        INTCONbits.TMR0IF = 0;
    }

    if (PIR1bits.TMR1IF) {
        TMR1H += 0x0B; //3036=0x0BDC
        TMR1L += 0xDC; ////250ms=0.5us*8*(65536-3036)
        PIR1bits.TMR1IF = 0;
        b++;
        if (b == 4) {
            digitalWrite(_RB6, !digitalRead(_RB6));
            b = 0;
        }
    }
}

void setup(void) {
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

    //Configura TMR1
    T1CONbits.TMR1ON = 0;
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1CKPS = 0b11; //divide por 8
    TMR1H = 0x0B; //3036=0x0BDC
    TMR1L = 0xDC; ////250ms=0.5us*8*(65536-3036)
    PIR1bits.TMR1IF = 0;
    INTCONbits.PEIE = 1; //Habilitando a interrupção
    PIE1bits.TMR1IE = 1; //Habilitando a interrupção
    T1CONbits.TMR1ON = 1;
}

void loop(void) {
}