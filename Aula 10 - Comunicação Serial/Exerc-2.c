#include"config.h"
#include "itoa.h"

void setup(void)
{
    pinMode(_RC7, INPUT); //RX como entrada
    TRISB = 0x00; // PORTB todo saida
    //O TRISD já é por padrão configurado como saida
}

char buffer[6];
int valor;
int c, d, u;

void loop(void)
{
    switch (Serial_read(0)) { //Serial_read(0) faz com que o programa fique parado aqui até receber um caractere
    case 'l':
        switch(Serial_read(0))
        {
            case 'b':
                PORTB = 0xFF;
                Serial_print("PORTB Ligado \r\n");
            break;
            
            case 'd':
                PORTD = 0xFF;
                Serial_print("PORTD Ligado \r\n");
            break;
        }
    break;
    case 'd':
        switch(Serial_read(0))
        {
            case 'b':
                PORTB = 0x00;
                Serial_print("PORTB Desligado \r\n");
            break;
            
            case 'd':
                PORTD = 0x00;
                Serial_print("PORTD Desligado \r\n");
            break;
        }
    break;
    case 'a':
        switch(Serial_read(0))
        {
            case '0':
                valor = analogRead(_AN0);
                Serial_print("A0= ");
                Serial_print(itoa(valor, buffer)); //Convertendo o valor lido como int do potenciometro P1 para string
            break;
            
            case '1':
                valor = analogRead(_AN1);
                Serial_print("A1= ");
                Serial_print(itoa(valor, buffer)); //Convertendo o valor lido como int do potenciometro P2 para string
            break;
            
            case '2':
                valor = analogRead(_AN2);
                Serial_print("A2= ");
                Serial_print(itoa(valor, buffer)); //Convertendo o valor lido como int do sensor de temp. para string
            break;
        }
        
        Serial_print("\r\n");
    break;
    case 'v':
        // -0x30 pega o valor inteiro de acordo com a tabela ASCII, pois o valor vem como char na leitura
        c = Serial_read(0) - 0x30; //CENTENA
        d = Serial_read(0) - 0x30; //DEZENA
        u = Serial_read(0) - 0x30; //UNIDADE
        
        valor = c * 100 + d * 10 + u;
        if(valor > 255)
            valor = 255;
        analogWrite(_RC2, valor);
        Serial_print("PWM= ");
        Serial_print(itoa(valor, buffer));
        Serial_print("\r\n");
    break;
    }
}