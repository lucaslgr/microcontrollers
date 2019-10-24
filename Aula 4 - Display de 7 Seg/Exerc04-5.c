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
    04.5- Faça um programa que mostre uma contagem hexadecimal nos 4 displays de 7 segmentos.
 *      1º - Realiza-se o mascaramento para pegar o valor que representará o valor na sua respetiva potência no display, exemplo, centena, dezena e unidade.
 *      2º - É realizado o deslocamento dos bits para que o valor seja representado apenas como 1 inteiro ao ser enviado para a função display7s()
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
    
    //Faz o mascaramento da variavel cont pegando o valor mais significativo e deslocando 12 bits para que o valor se torne apenas 1 valor inteiro
    PORTD = display7s((count & 0xF000)>>12);
    
    digitalWrite(_RA2, HIGH); //Setando o pino comum _RA2 do display de 7 segmentos como alto
    delay(30);//Delay de 500 mili-segundo.
    digitalWrite(_RA2, LOW); //Setando o pino comum _RA2 do display de 7 segmentos como baixo
    
    //Segundo valor mais significativo
    PORTD = display7s((count & 0x0F00)>>8);
    digitalWrite(_RA3, HIGH); //Setando o pino comum _RA3 do display de 7 segmentos como alto
    delay(30);//Delay de 500 mili-segundo.
    digitalWrite(_RA3, LOW); //Setando o pino comum _RA3 do display de 7 segmentos como baixo
    
    //Terceiro valor mais significativo
    PORTD = display7s((count & 0x00F0)>>4);
    digitalWrite(_RA4, HIGH); //Setando o pino comum _RA4 do display de 7 segmentos como alto
    delay(30);//Delay de 500 mili-segundo.
    digitalWrite(_RA4, LOW); //Setando o pino comum _RA2 do display de 7 segmentos como baixo
    
    //Menor valor significativo
    PORTD = display7s(count & 0x000F);
    digitalWrite(_RA5, HIGH); //Setando o pino comum _RA4 do display de 7 segmentos como alto
    delay(30);//Delay de 500 mili-segundo.
    digitalWrite(_RA5, LOW); //Setando o pino comum _RA2 do display de 7 segmentos como baixo
    
    count ++; //incrementa o contador
}