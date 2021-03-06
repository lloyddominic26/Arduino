#include "IRLibAll.h"
 
//Create a receiver object to listen on pin 2
IRrecvPCI myReceiver(2);
 
//Create a decoder object 
IRdecode myDecoder;   

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
  pinMode(3, OUTPUT);
}

void loop() {
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) {
    myDecoder.decode();           //Decode it
    myDecoder.dumpResults(false);  //Now print results. Use false for less detail
    myReceiver.enableIRIn();      //Restart receiver
  }
  if (myDecoder.decode()) {
    long int decCode = myDecoder.decode();
    if (decCode == "FF30CF"){
      digitalWrite(3, HIGH);
    }
    else {
      digitalWrite(3, LOW);
    }
  }
}
