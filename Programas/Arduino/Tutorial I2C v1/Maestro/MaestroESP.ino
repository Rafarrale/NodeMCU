#include <Wire.h>
#define I2CDireccionESPWifi 8
int x=32;

void setup()
{
 Serial.begin(115200);
 Wire.begin(4,5);//Cambiar a Wire.begin() para no ESP. Siendo D2(4) el SDA y el D1(5) SCL
}


void loop()
{
 Wire.beginTransmission(I2CDireccionESPWifi);
 Wire.write(x);
 Wire.endTransmission();
 x++;
 delay(1);//Espera al esclavo para calcular la respuesta.
 Wire.requestFrom(I2CDireccionESPWifi,10);
 Serial.print("Pidiendo respuesta:[");
 while (Wire.available())
 {
 delay(1);
 char c = Wire.read();
 Serial.print(c);
 }
 Serial.println("]");
 delay(500);
}
