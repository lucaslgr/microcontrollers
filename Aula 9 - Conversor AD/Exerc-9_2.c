/* Aula 09 
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
long int valor;
char buffer[6];

void loop()
{
    valor = analogRead(_AN0);
    lcd_cmd(L_L1);
    lcd_str(itoa(valor, buffer));
    lcd_cmd(L_L1 + 6);
    valor = valor * 5000 / 1023;
    
    //Colocando vírgula
    itoa(valor, buffer); //'04784'
    buffer[0] = buffer[1]; //'44784'
    buffer[1] = ',';
    lcd_str(buffer);
}