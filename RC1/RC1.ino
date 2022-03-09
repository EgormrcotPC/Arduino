#include <Gyver433.h>//синий
#include <avr/eeprom.h>

#define MAX_BUFFER 20
#define ASCII_CONVERT 0

char buffer[MAX_BUFFER];
byte send_buffer[MAX_BUFFER];
char data[MAX_BUFFER]; // строка для приема
byte count_buffer = 0;  // счётчик для отправки
byte count_data = 0;

byte ip = 0;
Gyver433_TX<8> tx;  // указали пин
Gyver433_RX<3, MAX_BUFFER> rx;  // указали пин и размер буфера

void setup() {
  Serial.begin(9600);  
  attachInterrupt(0, isr, CHANGE);  // прерывание пина радио по CHANGE
  pinMode(13, OUTPUT);

  // читаем
  ip = eeprom_read_byte(0);
}

void isr() {
  rx.tickISR();
}

// парсер. Возвращает количество принятых байтов даты
int parsing() {
  static bool parseStart = false;
  static byte counter = 0;
  if (Serial.available()) {
    char in = Serial.read();  
    Serial.print("in="+in);
    if (in == '\n' || in == '\r') return 0; // игнорируем перевод строки    
    if (in == ';') {        // завершение пакета
      parseStart = false;
      return counter;
    }    
    if (in == '$') {        // начало пакета
      parseStart = true;
      counter = 0;
      return 0;
    }    
    if (parseStart) {       // чтение пакета
      // - '0' это перевод в число (если отправитель print)
      buffer[counter] = in - ASCII_CONVERT;
      counter++;
      // Защита от переполнения буфера
      if (counter>=MAX_BUFFER) {
        parseStart = false;
        return counter;
      }
    }
  }
  return 0;
}

void loop() {
  // Читаем данные с компьютера
  //count_buffer=parsing();
//  count_buffer=3;
//  buffer[0]=33;
//  buffer[1]=34;
//  buffer[2]=35;
//  delay(500);
  
  //Serial.println("cnt="+String(count_buffer));
//  if (count_buffer>0) {
//    // Добавим IP-адрес в сообщение
//    send_buffer[0]=ip;
//    memcpy(&(send_buffer[1]), buffer, count_buffer);
//    count_buffer++;
//    
//    // отправка данных типа byte*
//    tx.write((byte*)send_buffer, count_buffer); //sizeof(buffer));
//    //tx.sendData(buffer);
//    Serial.print("send=");
//    Serial.println((char*)send_buffer);
//  }

  //s.toCharArray(&data[2], str_len);
  //Serial.println("str_len="+String(str_len));
 
  // ПРИЕМ ДАННЫХ ПО РАДИОКАНАЛУ  
//    count_data=rx.gotData(); // если пакет прочитан успешно - вернёт количество байт в нём
//             Serial.print("count=");
//         Serial.println(count_data);
//    if (count_data>0) {  // если успешно принято больше 0
//     if (rx.readData(data)) {
//         Serial.print("recive=");
//         Serial.println((char*)data);
//       if (data[0]!=ip) {
//         //Serial.print("recive=");
//         //Serial.println((char*)data);
//         // Выводим в COM-порт
//         Serial.write((byte*)data,count_data);
//         //digitalWrite(13, HIGH);
//       }
//     }
//    }
//    Serial.write(rx.buffer, rx.size);   // выводим
    
    //Serial.println();
    buffer[0]='1';
    tx.sendData(buffer);
    Serial.print("send=");
    Serial.println((char*)buffer);
  
        // выведем также качество соединения
    Serial.print(", RSSI: ");
    Serial.println(rx.getRSSI());
  delay(500);

    buffer[0]='2';
    tx.sendData(buffer);
    Serial.print("send=");
    Serial.println((char*)buffer);
  
        // выведем также качество соединения
    Serial.print(", RSSI: ");
    Serial.println(rx.getRSSI());
  delay(500);

}
