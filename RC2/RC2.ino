#include <Gyver433.h>
Gyver433_RX<2, 20> rx;  // указали пин и размер буфера
void setup() {
  Serial.begin(9600);  
  attachInterrupt(0, isr, CHANGE);  // прерывание пина радио по CHANGE
  pinMode(13, OUTPUT);
}
// спец. тикер вызывается в прерывании
void isr() {
  rx.tickISR();
}
void loop() {
  if (rx.gotData()) {                   // если успешно принято больше 0
    char data[20];
    if (rx.readData(data)) {
      if (data[0]=='1') {
        digitalWrite(13, HIGH);
      } else {
        digitalWrite(13, LOW);
      }
    }
    //Serial.write(rx.buffer, rx.size);   // выводим
    Serial.write(data);
    //Serial.println();
        // выведем также качество соединения
    Serial.print(", RSSI: ");
    Serial.println(rx.getRSSI());
  }
}
