
//import
import processing.serial.*;
Serial port;  // Create object from Serial class
//int
int password=2022;
int passin;
int temp=0;
int tm1=0;
int tm2=0;
int tm3=0;
//boolean
boolean access=true;
//string
String status="система оффлайн";

void setup() {
  size(900, 700);  // вызов функции size() должен быть первой строчкой
 {
  String[] port = Serial.list();
  for(int i = 0; i < port.length; i++){
    //print("COM4");
    println(Serial.list()[i]);
  }
 }
  port = new Serial(this, Serial.list()[0], 9600); 
}
void loop() {
  while (access==true){
    
  }
}
void keyPressed() {
  int keyIndex = -1;
  if (key == '1') {
    passin=passin+1;
  }
  if (key == '2') {
    passin=passin+2;
  }
  if (key == '3') {
    passin=passin+3;
  }
  if (key == '4') {
    passin=passin+4;
  }
  if (key == '5') {
    passin=passin+5;
  }
  if (key == '6') {
    passin=passin+6;
  }
  if (key == '7') {
    passin=passin+7;
  }
  if (key == '8') {
    passin=passin+8;
  }
  if (key == '9') {
    passin=passin+9;
  }
  if (key == '0') {
    passin=passin-9;
  }
  if (key == 'u') {
    if (passin==password){
      access=true;
    } 
       
  }
  if (key == 't') {
    if (access==true){
      if (key == '1') {
         
        if (key == '1') {
          tm1=10;
        }
        if (key == '2') {
          tm1=20;
        }
        if (key == '3') {
          tm1=30;
        }
        if (key == '4') {
          tm1=40;
        }
        if (key == '5') {
          tm1=50;
        }
        if (key == '6') {
          tm1=60;
        }
        if (key == '7') {
          tm1=70;
        }
        if (key == '8') {
          tm1=80;
        }
        if (key == '9') {
          tm1=90;
        }
        if (key == '0') {
          tm1=100;
        }
      }
      if (key == '2') {
        if (key == '1') {
          tm2=10;
        }
        if (key == '2') {
          tm2=20;
        }
        if (key == '3') {
          tm2=30;
        }
        if (key == '4') {
          tm2=40;
        }
        if (key == '5') {
          tm2=50;
        }
        if (key == '6') {
          tm2=60;
        }
        if (key == '7') {
          tm2=70;
        }
        if (key == '8') {
          tm2=80;
        }
        if (key == '9') {
          tm2=90;
        }
        if (key == '0') {
          tm2=100;
        }
        
      if (key == '3') {
        if (key == '1') {
          tm3=10;
        }
        if (key == '2') {
          tm3=20;
        }
        if (key == '3') {
          tm3=30;
        }
        if (key == '4') {
          tm3=40;
        }
        if (key == '5') {
          tm3=50;
        }
        if (key == '6') {
          tm3=60;
        }
        if (key == '7') {
          tm3=70;
        }
        if (key == '8') {
          tm3=80;
        }
        if (key == '9') {
          tm3=90;
        }
        if (key == '0') {
          tm3=100;
        }
      }  
    }
  } 
}
}

   


// Операторы draw () выполняются до остановки программы. 
// Каждый оператор выполняется последовательно и после того, 
// как будет выполнена последняя строка, первая строка выполняется снова.
void draw() { 
  if (access==false) {
    background(#ffffff);   // Очищаем экран белым фоном.
    fill(0, 102, 153);
    text(passin, 60, 60);  
  }
  if (access==true) {
    background(#ffffff);   // Очищаем экран белым фоном.
    fill(#00AF44);
    text("доступ разрешён", 60, 60);
    fill(#000301);
    text("температура:", 80, 100);
    text(temp, 155, 101);
    text("статус:", 80, 120);
    text(status, 123, 120);
    text("мощьность турбины 1 :", 80, 140);
    text(tm1, 210, 140);
    text("мощьность турбины 2 :", 80, 160);
    text(tm2, 210, 160);
    text("мощьность турбины 3 :", 80, 180);
    text(tm3, 210, 180);
    text("контроль энергии", 80, 200);
    
  }
 }
