#include"config.h"
#include "display7s.h"


char a, b, c;

char min = 0;
char seg = 0;

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

    if (PIR1bits.TMR2IF) {
        PIR1bits.TMR2IF = 0;
        c++;
        if (c == 50) {
            digitalWrite(_RB7, !digitalRead(_RB7));
            c = 0;

            seg++;
            if (seg == 60) {
                seg = 0;
                min++;
            }
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
    PIE1bits.TMR1IE = 1; //Habilitando a interrupção para o Timer01
    T1CONbits.TMR1ON = 1;

    //Configura TMR2
    T2CONbits.TMR2ON = 0;
    T2CONbits.T2CKPS = 0b11; //divide por 16
    T2CONbits.TOUTPS = 0b1001; //divide por 10
    TMR2 = 0;
    PR2 = 249; //20ms=0.5us*16*(249+1)*10
    PIE1bits.TMR2IE = 1; //Habilitando a interrupção para o Timer02
    T2CONbits.TMR2ON = 1;


    //Configurando o display de 7seg
    pinMode(_RA2, OUTPUT);
    pinMode(_RA3, OUTPUT);
    pinMode(_RA4, OUTPUT);
    pinMode(_RA5, OUTPUT);
    digitalWrite(_RA2, LOW);
    digitalWrite(_RA3, LOW);
    digitalWrite(_RA4, LOW);
    digitalWrite(_RA5, LOW);
}

void loop(void) {
    /*Mostra 1 no display 1*/
    PORTD = display7s(min/10);
    digitalWrite(_RA2, HIGH);
    delay(1);
    digitalWrite(_RA2, LOW);
    
    /*Mostra 2 no display 2*/
    PORTD = display7s(min%10);
    digitalWrite(_RA3, HIGH);
    delay(1);
    digitalWrite(_RA3, LOW);
    
    /*Mostra 2 no display 3*/
    PORTD = display7s(seg/10);
    digitalWrite(_RA4, HIGH);
    delay(1);
    digitalWrite(_RA4, LOW);
    
    /*Mostra 2 no display 4*/
    PORTD = display7s(seg%10);
    digitalWrite(_RA5, HIGH);
    delay(1);
    digitalWrite(_RA5, LOW);
}