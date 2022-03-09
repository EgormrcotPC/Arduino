void setup() {               
  // Инициализируем цифровой вход/выход в режиме выхода.
  // Выход 13 на большинстве плат Arduino подключен к светодиоду на плате.
  pinMode(13, OUTPUT);   
}
 
void loop() {
  digitalWrite(13, HIGH);   // зажигаем светодиод
  delay(100);              // ждем секунду
  digitalWrite(13, LOW);    // выключаем светодиод
  delay(500);              // ждем секунду
  digitalWrite(13, HIGH);
  delay(500); 
  digitalWrite(13, LOW);
  delay(500); 
}
