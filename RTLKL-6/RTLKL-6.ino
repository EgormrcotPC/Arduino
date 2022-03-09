#define pinPot A1
#define pinLed 11
#define pinBtn 2

void setup() {

  pinMode(pinPot, INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBtn, INPUT_PULLUP);


  Serial.begin(9600);
  Serial.println("The program starts.\n\n");

}

void loop() {

  /* INITIAL VARIABLES. Segment 1 */
  static char potMes[]  = "Pot - ";
  static char btnMes[] = "Button is pressed!";
  static char passLight[] = "Led - ";
  static int passLength = sizeof(passLight) - 1;
  static int sizepm = sizeof(potMes) - 1;
  static int sizebtn = sizeof(btnMes) - 1;

  static bool flagLedState = LOW;
  static bool flagBtnPress = false;
  static long int curTime = 0;
  static const int period = 200; 
  static bool flagEnableRead = false;
  /* INITIAL VARIABLES. Segment 1 */

  /* FUNCTIONS CALL. Segment 2 */

  /*
   * Led is attached to HIGH voltage from one side
   * And to pin on the other side
   * By that the inverting logic
   */
  ReadSerialForLed(passLight, passLength, &flagLedState);
  digitalWrite(pinLed, !flagLedState);
  
  /*
   * Button pin always is pulled to the HIGH voltage
   * And only when button is pressed - Voltage on pin goes to GROUND
   * So it is need to invert logic when read pins 
  */
  if(!Bounce(pinBtn) && flagBtnPress == false){
   
    for(int i = 0; i < sizebtn; i++){
       Serial.write(btnMes[i]);
    }
    Serial.print("\n");
    flagBtnPress = true;
    
    if(!flagEnableRead){
      curTime = millis();
      flagEnableRead = true;
    }
    
  }else if(Bounce(pinBtn)){
    flagBtnPress = false;
  }

  /*
   * Read and send Info "Pot - " + var Only after first press on button
   * Every 'period'ms
   */
  if(millis() - curTime > period && flagEnableRead){
    SendData(pinPot, potMes, sizepm);
    curTime = millis();
  }
  /* FUNCTIONS CALL. Segment 2 */
  
}
/*
 * Pot - pin with potentiometer
 * pMes - Array with message before Pot value
 * sp - size of potentiometer message
 */
void SendData(int Pot, char* pMes, int sp){

  static int varP[2];
  
  varP[0] = analogRead(Pot);
  
  varP[1] = varP[0]/256; // 0 - 3 (256 - 1024)
  varP[0] = varP[0]%256; // 0 - 255

  //Send Message
  for(int i = 0; i < sp; i++){
    Serial.write(char(pMes[i]));
  }
  //Send 2 bits of data
  //Serial.write(varP[0]);
  //Serial.write(varP[1]);

  Serial.print(analogRead(Pot));
  Serial.print("\n");

}

/*
 * Function, which is reads button pin with the bounce
 */
bool Bounce(int btn){
  
  if(digitalRead(btn) == true){
    delay(15);
    if(digitalRead(btn) == true){
      return true;
    }else{
      return false;
    }
  }else{
    return false;
  }

}

/*
 * If Message from Serial port, which you read will be the same to passLight
 * So look at the next symbol after Pass Message. If it is symbol 'H' - make LED to light
 * If it is 'L' - make LED off.
 */
void ReadSerialForLed(char *passLight_f, int passLength_f, bool* flagLedState_f){
  
  static char sym;
  static int cntPass = 0;
  static bool readyGetLed = LOW;

  while (Serial.available() > 0) {
    
    sym = Serial.read();

    if(sym == passLight_f[cntPass] && !readyGetLed){
      cntPass++;
    }else if (!readyGetLed){
      cntPass = 0;
    }else if(readyGetLed){
      if(sym == 'H'){
        *flagLedState_f = HIGH;
      }else if(sym == 'L'){
        *flagLedState_f = LOW;
      }
    }

    if(cntPass == passLength_f){
      readyGetLed = HIGH;
    }
  }
  
}
