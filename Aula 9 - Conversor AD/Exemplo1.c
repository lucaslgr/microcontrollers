/* Aula 09 
 * Exemplo 9 - Conversor AD de 10 bits(0-1023). 
 */

#include"config.h"
#include"lcd.h"
#include"itoa.h"

void setup()
{
    lcd_init();
    lcd_cmd(L_CLR);
    lcd_cmd(L_NCR);
}
unsigned int valor;
char buffer[6];

void loop()
{
    valor = analogRead(_AN0);
    lcd_cmd(L_L1);
    lcd_str(itoa(valor, buffer));
    lcd_cmd(L_L1 + 6);
    valor = valor * 50 / 1023;
    lcd_str(itoa(valor, buffer));
}