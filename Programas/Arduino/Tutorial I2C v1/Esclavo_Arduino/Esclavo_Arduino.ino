#include <Wire.h>
#define I2CDireccionESPWifi 8
char respuesta[11] ="0123456789";


void setup()
{
 Serial.begin(115200);
 Wire.begin(I2CDireccionESPWifi);
 Wire.onReceive(espWifiRecibeEvento);
 Wire.onRequest(peticion); //Creamos el evento que se realizara cuando el recptor llame a el emidor (Este dispositivo)
}


void loop()
{
 delay(1);
}


void peticion(int count)
{
 Serial.print("Recibido[");
 while (Wire.available())
 {
 char c = Wire.read();
 Serial.print(c);
 }
 Serial.println("]");
 //calcula respuesta.
}


void espWifiRespuestaEvento()
{
 Wire.write(respuesta); //Enviar el mensaje
}

