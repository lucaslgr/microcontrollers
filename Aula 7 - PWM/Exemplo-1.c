/* PWM - usando tmr0 (placa 1)*/
#include"config.h"
#define _tmr0_ini 56
unsigned char cnt;
unsigned char nivel;

void interrupt isr(void) //a cada 100us
{
    TMR0 = _tmr0_ini; //reinicia contagem
    if (cnt < nivel) //quando contagem = 0;
    {
        digitalWrite(_RC5, HIGH);
    } else {
        digitalWrite(_RC5, LOW);
    }
    cnt = cnt + 1;
    if (cnt > 9)cnt = 0;
    INTCONbits.TMR0IF = 0; // reseta flag TMR0
}

void setup(void) {
    /*configuracao TMR0 */
    //Clock do tmr0 como clock_cpu/4
    T0CONbits.T0CS = 0;
    //Usa pre-scaler
    T0CONbits.PSA = 0;
    T0CONbits.T0PS = 0; //divide por 2
    //modo 8 bits
    T0CONbits.T08BIT = 1;
    //Conta de 56 a 0 (200)
    TMR0 = _tmr0_ini;
    /* tempo entre interrupcoes =
    ((200*10)/(Fosc/4)= p/ 8MHz=>1ms*/
    /* configura interrupcoes */
    INTCONbits.GIE = 1; //liga int.
    INTCONbits.TMR0IE = 1; //liga int. do TMR0
    INTCONbits.TMR0IF = 0; //Apaga flag de int.
    T0CONbits.TMR0ON = 1; //liga TMR1
    nivel = 5; //começa na metade
    
    PORTD = 0;
}

void loop(void) {
    if (!digitalRead(_RB1)) {
        delay(10);
        if (!digitalRead(_RB1)) {
            if (nivel < 10)
                nivel = nivel + 1;
            while (!digitalRead(_RB1));
        }
    }
    if (!digitalRead(_RB2)) {
        delay(10);
        if (!digitalRead(_RB2)) {
            if (nivel > 0)
                nivel = nivel - 1;
            while (!digitalRead(_RB2));
        }
    }
}
