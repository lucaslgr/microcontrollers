/*Aula 08 - EEPROM e LCD*/
#include"config.h"
#include"lcd.h"
#include"itoa.h"
#include "eeprom.h"

unsigned char a = '0';
char buffer[6];
unsigned char addr = 10; //Endereço na memória EEPROM para salvar o valor

void setup() {
    lcd_init();
    lcd_cmd(L_CLR);
    lcd_cmd(L_NCR);
    lcd_cmd(L_L1 + 3);
    //lcd_str("Karine eh doida");
    lcd_str("Teste");
    delay(1000);

    //Teste, colorindo todo o LCD
    lcd_custom(0, 0x4, 0xe, 0x1f, 0x4, 0xe, 0x15, 0x4, 0x4);
    lcd_custom(1, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13);
    lcd_custom(2, 0b1010, 0b10101, 0b1010, 0b10101, 0b1010, 0b10101, 0b1010, 0b10101);
    lcd_custom(3, 0xe, 0x1b, 0xe, 0x15, 0x11, 0x1f, 0xa, 0x1b);
    //Recupera o valor lido e armazenado no endereço específicado
    a = eeprom_r(addr);
    if ((a < '0') || (a > 'z'))
        a = '0';
}

unsigned char j = 0;

void loop() {
    lcd_cmd(L_L2);
    lcd_dat(a);
    lcd_cmd(L_L2 + 4);
    lcd_str(itoa(a, buffer));
    a++;
    if (a > 'z')a = '0';
    eeprom_w(addr, a);

    //Rotina para trocar o caractere
    lcd_dat(j % 4);
    delay(100);
    j++;

    //Código para deslocar o cursor
    char i;
    lcd_cmd(L_NCR);
    for (i = 0; i < 10; i++) {
        delay(200);
        lcd_cmd(0x18); //display shift
    }
    for (i = 0; i < 10; i++) {
        delay(200);
        lcd_cmd(0x1C); //display shift
    }
    lcd_cmd(L_CR);
    for (i = 0; i < 10; i++) {
        delay(200);
        lcd_cmd(0x10);
    }
    for (i = 0; i < 10; i++) {
        delay(200);
        lcd_cmd(0x14);
    }
    delay(300);
}
