#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

const int buttonPin = 2;

int buttonState = 0; 

void setup()
{
    Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    char *mes;
    buttonState = digitalRead(buttonPin);
      
    if (buttonState == HIGH) {
      mes="1";
    } 
    
    else {
      mes="0";
    }
    driver.send((uint8_t *)mes, strlen(mes));
    driver.waitPacketSent();
    delay(100);
}


