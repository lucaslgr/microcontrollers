/*
 * File:   main.c
 * Author: guima
 *
 * Created on 28 de Agosto de 2019, 13:47
 */

// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

#include "config.h"
#include "display7s.h"

/*
    04.2- Altere o programa anterior para mostrar o número 2 no primeiro display de 7 segmentos.
 */

void setup() {
    //Configurando os pinos COMUNS de cada apresentação de caracter no display como saída
    pinMode(_RA2, OUTPUT);
    pinMode(_RA3, OUTPUT);
    pinMode(_RA4, OUTPUT);
    pinMode(_RA5, OUTPUT);
    //Mantendo todos pinos comuns dos blocos de caracteres desligados
    digitalWrite(_RA2, LOW);
    digitalWrite(_RA3, LOW);
    digitalWrite(_RA4, LOW);
    digitalWrite(_RA5, LOW);
}

void loop() {
    PORTD = 0b00000110; //Mostra o número 1 setando os bits da porta D no formato binário
    //PORTD = 0x06; //Mostra o número 1 setando os bits da porta D no formato HEXA
    //PORTD = display7s(1); //Usa a função display7s() para setar o valor que deverá aparecer no display
    digitalWrite(_RA2, HIGH); //Setando o pino comum _RA2 do display de 7 segmentos como alto
    digitalWrite(_RA3, HIGH); //Setando o pino comum _RA3 do display de 7 segmentos como alto
    digitalWrite(_RA4, HIGH); //Setando o pino comum _RA4 do display de 7 segmentos como alto
    delay(1);//Delay de 1 mili-segundo.
    digitalWrite(_RA2, LOW); //Setando o pino comum _RA2 do display de 7 segmentos como baixo
    digitalWrite(_RA3, LOW); //Setando o pino comum _RA3 do display de 7 segmentos como baixo
    digitalWrite(_RA4, LOW); //Setando o pino comum _RA4 do display de 7 segmentos como baixo
    
    
    PORTD = 0b01011011; //Mostra o número 1 setando os bits da porta D no formato binário
    //PORTD = 0x5B; //Mostra o número 1 setando os bits da porta D no formato HEXA
    //PORTD = display7s(1); //Usa a função display7s() para setar o valor que deverá aparecer no display
    digitalWrite(_RA5, HIGH); //Setando o pino comum _RA5 do display de 7 segmentos como alto
    delay(1);//Delay de 1 mili-segundo.
    digitalWrite(_RA5, LOW); //Setando o pino comum _RA5 do display de 7 segmentos como baixo
}