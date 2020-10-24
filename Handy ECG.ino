#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>
#define USERNAME "AreebaAsif"
#define DEVICE_ID "ECG"
#define DEVICE_CREDENTIAL "rehman@linkgiz"

 //defining SSID and password for the router
 #define SSID "Mani"
 #define SSID_PASSWORD "password"
 ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

 void setup(){
 thing.add_wifi(SSID, SSID_PASSWORD);

Serial.begin(9600);
pinMode(D5, INPUT); // Setup for leads off detection LO +
pinMode(D6, INPUT); // Setup for leads off detection LO -

   
  thing["ECG"] >> [] (pson& out){
float h = analogRead(A0);
  
 
if((digitalRead(D5) == 1)||(digitalRead(D6) == 1))
{
Serial.println('!');
h = 0;
      out = h;
}
else{
// send the value of analog input 0:
Serial.println(analogRead(A0));
h = analogRead(A0);
      out = h;
}
//Wait for a bit to keep serial data from saturating
delay(1);
  };

   thing["BED"] >> [] (pson& out){
float a = analogRead(A0);
  
 
if((digitalRead(D5) == 1)||(digitalRead(D6) == 1))
{
Serial.println('!');
a = 1;
      out = a;
}
else{
// send the value of analog input 0:
Serial.println(analogRead(A0));
a = 0;
      out = a;
}
//Wait for a bit to keep serial data from saturating
delay(1);
  };
  
}

 void loop(){
    thing.handle();
     // Serial.print(F("Humidity: "));

}
