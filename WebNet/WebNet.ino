                                                                                String val;
String IP = "971.883.209.62";

void setup() {
        Serial.begin(9600);
        pinMode(13,OUTPUT); 
}

void loop() {
  if (Serial.available() > 0) {
    val = Serial.readString();}
    if (val=='1') {
      digitalWrite(13,HIGH); delay (100);
      digitalWrite(13,LOW); delay (100);
    }
    if (val=='2') {
      digitalWrite(13,HIGH); delay (500);
      digitalWrite(13,LOW); delay (500);
    }
    if (val=="привет") {
      //Serial.print('привет');
      Serial.write(52);
    }
    val='0';
}
