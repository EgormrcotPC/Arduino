#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
//RCSwitch mySwitch2 = RCSwitch();

void setup() {
  // put your setup code here, to run once:
  mySwitch.enableTransmit(2);
  //mySwitch2.enableTransmit(3);
  //pinMode (13, OUTPUT );  
  // set protocol (default is 1, will work for most outlets)
 mySwitch.setProtocol(2);
 // Optional set number of transmission repetitions.
 mySwitch.setRepeatTransmit(15);
}

void loop() {
  // put your main code here, to run repeatedly:
  mySwitch.send(B0100, 4);
  delay(1000); 
  mySwitch.send(B1000, 4);
  delay(1000); 
//  if( mySwitch2.available() ){
//        int value = mySwitch2.getReceivedValue();
// 
//        if( value == B1000 )
//            digitalWrite( 13, HIGH );
//        else if( value == B0100 )
//            digitalWrite( 13, LOW );
//
//        mySwitch2.resetAvailable();
//
//  }
}
