#include"config.h"
#include"lcd.h"
#define _VENT 0x00
#define _VSAI 0x01
#define _AQUE 0x02
#define _RESF 0x03
#define _AGIT 0x04
#define _LIGA 0x01
#define _DESLIGA 0x00

void setup(void)
{
    pinMode(_RC7, INPUT);
    lcd_init();
    lcd_cmd(L_CLR);
    Serial_write(0xFF); //sincroniza comunicação
    Serial_write(0xFF);
    Serial_write(0xFF);
}

void loop(void)
{
    Serial_write(_VENT);
    Serial_write(_LIGA);
    Serial_write(_VSAI);
    Serial_write(_DESLIGA);
    lcd_cmd(L_L1);
    lcd_str("Enche ");
    delay(1000);
    Serial_write(_VENT);
    Serial_write(_DESLIGA);
    Serial_write(_VSAI);
    Serial_write(_LIGA);
    lcd_cmd(L_L1);
    lcd_str("Esvazia");
    delay(1000);
}