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
    lcd_cmd(L_L1+3);
    //lcd_str("Karine eh doida");
    lcd_str("Teste");
    delay(1000);
    //Recupera o valor lido e armazenado no endereço específicado
    a = eeprom_r(addr);
    if((a<'0') || (a>'z'))
        a='0';
}

void loop() {
    lcd_cmd(L_L2);
    lcd_dat(a);
    lcd_cmd(L_L2 + 4);
    lcd_str(itoa(a, buffer));
    a++;
    if (a > 'z')a = '0';
    eeprom_w(addr,a);
    delay(300);
}
