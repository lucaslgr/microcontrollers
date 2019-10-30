#include"config.h"

void setup(void)
{
    pinMode(_RC7, INPUT); //RX como entrada
    TRISB = 0x00; // PORTB todo sa√da
}

void loop(void)
{
    switch (Serial_read(0)) {
    case 'l':
        PORTB = 0xFF;
        Serial_print("PORTB Ligado\r\n");
        break;
    case 'd':
        PORTB = 0x00;
        Serial_print("PORTB Desligado\r\n");
        break;
    }
}