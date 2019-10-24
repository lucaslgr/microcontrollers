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
    04.6- Faça um programa que mostre uma contagem decimal nos 4 displays de 7 segmentos..
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

//variável global contador
int count = 0;

void loop() {
    
    //Apenas divide o valor pela potência de milhar, que é a potência que o representa
    PORTD = display7s(count / 1000);
    
    digitalWrite(_RA2, HIGH); //Setando o pino comum _RA2 do display de 7 segmentos como alto
    delay(1);//Delay de 500 mili-segundo.
    digitalWrite(_RA2, LOW); //Setando o pino comum _RA2 do display de 7 segmentos como baixo
    
    //Segundo valor mais significativo
    PORTD = display7s((count % 1000)/100);
    digitalWrite(_RA3, HIGH); //Setando o pino comum _RA3 do display de 7 segmentos como alto
    delay(1);//Delay de 500 mili-segundo.
    digitalWrite(_RA3, LOW); //Setando o pino comum _RA3 do display de 7 segmentos como baixo
    
    //Terceiro valor mais significativo
    PORTD = display7s((count % 100)/10);
    digitalWrite(_RA4, HIGH); //Setando o pino comum _RA4 do display de 7 segmentos como alto
    delay(1);//Delay de 500 mili-segundo.
    digitalWrite(_RA4, LOW); //Setando o pino comum _RA2 do display de 7 segmentos como baixo
    
    //Menor valor significativo
    PORTD = display7s(count %10);
    digitalWrite(_RA5, HIGH); //Setando o pino comum _RA4 do display de 7 segmentos como alto
    delay(1);//Delay de 500 mili-segundo.
    digitalWrite(_RA5, LOW); //Setando o pino comum _RA2 do display de 7 segmentos como baixo
    
    count ++; //incrementa o contador
}