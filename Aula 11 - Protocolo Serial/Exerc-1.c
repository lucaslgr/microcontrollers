#include"config.h"

void setup(void)
{
    pinMode(_RC7, INPUT); //RX como entrada
    TRISB = 0x00; // PORTB todo saÃda
    //O TRISD já é por padrão configurado como saida
}

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
    }
}