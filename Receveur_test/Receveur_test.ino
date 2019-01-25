#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile


RH_ASK driver;

int led = 7;

void setup()
{
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");
         
    pinMode(led, OUTPUT);
}

void loop()
{
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
   
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Rec: ");
      Serial.println(buf[0]);  

        /*if(buf[0] == "1")
        {
            digitalWrite(led, HIGH);
        }
        else
        {
            digitalWrite(led, LOW);
        }*/
    }
    
 }


