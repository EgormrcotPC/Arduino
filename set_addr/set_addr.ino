#include <avr/eeprom.h>
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  // объявляем данные разных типов
  //byte addr = 211; // адрес первой ардуины (синяя)
  byte addr = 96; // адрес второй ардуины (желтая)
  // пишем друг за другом
  eeprom_write_byte(0, addr);  // 1 байт
  

   // объявляем переменные, куда будем читать
  byte dataB_read = 0;
  // читаем
  dataB_read = eeprom_read_byte(0);

  // выведет 120 3.14 -634
  Serial.println(dataB_read);
}

void loop() {
  // put your main code here, to run repeatedly:

}
