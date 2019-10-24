/* Aula 10
 */

#include "teclado.h"
#include "config.h"
#include "lcd.h"

void setup()
{
    lcd_init();
    lcd_cmd(L_CLR);
    Serial_print("Digite!");
    pinMode(_RC7, INPUT); //RX entrada
    TRISB = 0xF8; //configura RB0, RB1 e RB2 como saida
}
char linha_[17];
char valor;

void loop()
{
    lcd_cmd(L_L1);
    serial_rx_str_until(linha_,16,'\n');
    lcd_str(linha_);
    lcd_str("                ");//15 espaços
    
    
    lcd_cmd(L_L2);
    TRISD = 0x0F; //Configura RD0, RD1, RD2, RD3 como entrada
    valor = tc_tecla(0)+0x30;
    TRISD = 0x00;
    serial_tx(valor);
    lcd_dat(valor);
}