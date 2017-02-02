#include <Wire.h>
#define I2CDireccionESPWifi 8
int x=32;

void setup()
{
 Serial.begin(115200);
 //Iniciamos el wire I2C
 Wire.begin(4,5);//Cambiar a Wire.begin() para no ESP. Siendo D2(4) el SDA y el D1(5) SCL
}


void loop()
{
 Wire.beginTransmission(I2CDireccionESPWifi);
 Wire.write(x); //Enviar el mensaje
 Wire.endTransmission();
 x++;
 delay(1);//Espera al esclavo para calcular la respuesta.
 Wire.requestFrom(I2CDireccionESPWifi,10); //Se envia una petion en el canal 8 de 10 caracteres
 Serial.print("Pidiendo respuesta:[");
 
 while (Wire.available())
 {
 delay(1);
 char c = Wire.read(); //Guardamos el mensaje
 Serial.print(c); //Se imprime
 }
 Serial.println("]");
 delay(500);
}
