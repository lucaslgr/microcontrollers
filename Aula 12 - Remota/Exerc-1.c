#include"config.h"
#include"lcd.h"
#define _VENT 0x00
#define _VSAI 0x01
#define _AQUE 0x02
#define _RESF 0x03
#define _AGIT 0x04
#define _LIGA 0x01
#define _DESLIGA 0x00

//Entradas digitais
#define _BALT 0x10
#define _BBAI 0x11
#define _AMIN 0x12
#define _AMAX 0x13

//Saídas Analógicas
#define _TMIN 0x20
#define _TMAX 0x21

//Entradas Analógicas
#define _VOLU 0x30
#define _TEMP 0x31

void setup(void)
{
    pinMode(_RC7, INPUT);
    lcd_init();
    lcd_cmd(L_CLR);
    Serial_write(0xFF); //sincroniza comunicaÃ§Ã£o
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
    //Lendo a boia alta
    do{
        Serial_write(_BALT);
    } while(Serial_read(0) == 0); //Quando atingir o nível da boia alta, a leitura reotorna 1 e o loop continua
    
    //delay(1000);
    Serial_write(_VENT);
    Serial_write(_DESLIGA);
    Serial_write(_VSAI);
    Serial_write(_LIGA);  
    lcd_cmd(L_L1);
    lcd_str("Esvazia");
    //Lendo a boia baixa
    do{
        Serial_write(_BBAI);
    }while(Serial_read(0) == 1);//Quando atingir o nível da boia alta, a leitura reotorna 1 e o loop continua
}