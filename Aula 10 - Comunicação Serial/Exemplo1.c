/* Aula 10
 */

#include"config.h"
#include"lcd.h"

void setup()
{
    lcd_init();
    lcd_cmd(L_CLR);
    Serial_print("Digite!");
    pinMode(_RC7, INPUT); //RX entrada
}
char valor;

void loop()
{
    valor = Serial_read(0);
    lcd_cmd(L_L1);
    lcd_dat(valor);
    valor++;
    lcd_str(" -> ");
    lcd_dat(valor);
    Serial_write(valor);
}