/*Aula 08 - EEPROM e LCD*/
#include"config.h"
#include"lcd.h"
#include"itoa.h"
unsigned char a = '0';
char buffer[6];

void setup() {
    lcd_init();
    lcd_cmd(L_CLR);
    lcd_cmd(L_NCR);
    lcd_cmd(L_L1+3);
    //lcd_str("Karine eh doida");
    lcd_str("Teste");
    delay(1000);
}

void loop() {
    lcd_cmd(L_L2);
    lcd_dat(a);
    lcd_cmd(L_L2 + 4);
    lcd_str(itoa(a, buffer));
    a++;
    if (a > 'z')a = '0';
    delay(300);
}
