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
      int condition = (char)buf[0] - 48;
      Serial.print("Rec: ");
      Serial.println(condition);  

        if(condition == 1)
        {
            digitalWrite(led, HIGH);
            Serial.println("Okay");
        }
        else
        {
            digitalWrite(led, LOW);
        }
    }
    
 }


