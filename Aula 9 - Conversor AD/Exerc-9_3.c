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
    
    digitalWrite(_RC5, HIGH);
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
    //lcd_str(itoa(valor, buffer));
    itoa(valor, buffer);    //'04784'
    buffer[0] = buffer[1];  //'44784'
    buffer[1] = ',';
    lcd_str(buffer); 
    
    valor = analogRead(_AN2);
    lcd_cmd(L_L2);
    lcd_str(itoa(valor, buffer));
    lcd_cmd(L_L2 + 6);
    valor = valor * 5000 / 1023;
    itoa(valor, buffer);
    buffer[1] = buffer[2];
    buffer[2] = buffer[3];
    buffer[3] = ',';
    lcd_str(buffer); 
}