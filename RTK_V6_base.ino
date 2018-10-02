#include <SoftwareSerial.h>
SoftwareSerial bluetooth(15, 19);
int IN1_1 = 1; //правый задний вперед
int IN2_1 = 2; //правый задний назад
int IN3_1 = 4; //правый передний вперед
int IN4_1 = 5; //правый передний назад
int IN1_2 = 7; //левый задний вперед
int IN2_2 = 8; //левый задний назад
int IN3_2 = 12; //левый передний вперед
int IN4_2 = 13; //левый передний назад
int i;          //33 F9 платформа 3A 84 клешня
int spd1_1 = 3;
int spd2_1 = 6;
int spd1_2 = 10;
int spd2_2 = 11;
char msg;
int sensR = 16;
int sensL = 17;
int valL, valR;
char msg_spd;
boolean isAuto = false;
void setup() {
  //Serial.begin(115200);
  bluetooth.begin(9600);
  pinMode(IN1_1, OUTPUT);
  pinMode(IN2_1, OUTPUT);
  pinMode(IN3_1, OUTPUT);
  pinMode(IN4_1, OUTPUT);
  pinMode(IN1_2, OUTPUT);
  pinMode(IN2_2, OUTPUT);
  pinMode(IN3_2, OUTPUT);
  pinMode(IN4_2, OUTPUT);
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN1_2, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, LOW);
  digitalWrite(IN4_2, LOW);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  analogWrite(spd1_1, 100);
  analogWrite(spd1_2, 100);
  analogWrite(spd2_1, 100);
  analogWrite(spd2_2, 100);
  pinMode(sensL, INPUT);
  pinMode(sensR, INPUT);
}

void forward() {

  digitalWrite(IN1_1, HIGH);
  digitalWrite(IN3_1, HIGH);
  digitalWrite(IN1_2, HIGH);
  digitalWrite(IN4_2, HIGH);
  delay(45);
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN1_2, LOW);
  digitalWrite(IN4_2, LOW);

}

void backward() {

  digitalWrite(IN2_1, HIGH);
  digitalWrite(IN4_1, HIGH);
  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN3_2, HIGH);
  delay(45);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, LOW);

}

void right() {

  digitalWrite(IN2_1, HIGH);
  digitalWrite(IN4_1, HIGH);
  digitalWrite(IN1_2, HIGH);
  digitalWrite(IN4_2, HIGH);
  delay(45);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN1_2, LOW);
  digitalWrite(IN4_2, LOW);

}

void left() {

  digitalWrite(IN1_1, HIGH);
  digitalWrite(IN3_1, HIGH);
  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN3_2, HIGH);
  delay(45);
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, LOW);

}

void stay(){

    digitalWrite(IN1_1, LOW);
    digitalWrite(IN2_1, LOW);
    digitalWrite(IN3_1, LOW);
    digitalWrite(IN4_1, LOW);
    digitalWrite(IN1_2, LOW);
    digitalWrite(IN2_2, LOW);
    digitalWrite(IN3_2, LOW);
    digitalWrite(IN4_2, LOW);
    delay(45);
  
}

void lineGO(){
     analogWrite(spd1_1, 80);
     analogWrite(spd1_2, 80);
     analogWrite(spd2_1, 80);
     analogWrite(spd2_2, 80);
     if(valR == valL){
        forward(); 
      }
     
      if(valR < valL){
      analogWrite(spd1_1, 200);
      analogWrite(spd1_2, 200);
      analogWrite(spd2_1, 200);
      analogWrite(spd2_2, 200);
      right();
      }
      if(valR > valL){
      analogWrite(spd1_1, 200);
      analogWrite(spd1_2, 200);
      analogWrite(spd2_1, 200);
      analogWrite(spd2_2, 200);
      left();
      }  
    
    
}
void loop() {
  valL = (int)digitalRead(sensL);
  valR = (int)digitalRead(sensR);
  /*if(Serial.available()){
    Serial.print(valL);
    Serial.print(' ');
    Serial.println(valR);
  } */
  if (bluetooth.available()) {

    
   
    
    delay(1);
    if (msg == 'F') {

      forward();

    }

    if (msg == 'B') {

      backward();

    }

    if (msg == 'L') {

      left();

    }

    if (msg == 'R') {

      right();

    }

    if (msg == '0') {

      analogWrite(spd1_1, 0);
      analogWrite(spd1_2, 0);
      analogWrite(spd2_1, 0);
      analogWrite(spd2_2, 0);
      msg_spd = msg;

    }

    if (msg == '1') {

      analogWrite(spd1_1, 100);
      analogWrite(spd1_2, 100);
      analogWrite(spd2_1, 100);
      analogWrite(spd2_2, 100);
      msg_spd = msg;

    }

    if (msg == '2') {

      analogWrite(spd1_1, 160);
      analogWrite(spd1_2, 160);
      analogWrite(spd2_1, 160);
      analogWrite(spd2_2, 160);
      msg_spd = msg;

    }

    if (msg == '3') {

      analogWrite(spd1_1, 170);
      analogWrite(spd1_2, 170);
      analogWrite(spd2_1, 170);
      analogWrite(spd2_2, 170);
      msg_spd = msg;

    }

    if (msg == '4') {

      analogWrite(spd1_1, 180);
      analogWrite(spd1_2, 180);
      analogWrite(spd2_1, 180);
      analogWrite(spd2_2, 180);
      msg_spd = msg;

    }

    if (msg == '5') {

      analogWrite(spd1_1, 190);
      analogWrite(spd1_2, 190);
      analogWrite(spd2_1, 190);
      analogWrite(spd2_2, 190);
      msg_spd = msg;

    }

    if (msg == '6') {

      analogWrite(spd1_1, 200);
      analogWrite(spd1_2, 200);
      analogWrite(spd2_1, 200);
      analogWrite(spd2_2, 200);
      msg_spd = msg;
    }

    if (msg == '7') {

      analogWrite(spd1_1, 210);
      analogWrite(spd1_2, 210);
      analogWrite(spd2_1, 210);
      analogWrite(spd2_2, 210);
      msg_spd = msg;

    }

    if (msg == '8') {

      analogWrite(spd1_1, 220);
      analogWrite(spd1_2, 220);
      analogWrite(spd2_1, 220);
      analogWrite(spd2_2, 220);
      msg_spd = msg;

    }

    if (msg == '9') {

      analogWrite(spd1_1, 230);
      analogWrite(spd1_2, 230);
      analogWrite(spd2_1, 230);
      analogWrite(spd2_2, 230);
      msg_spd = msg;

    }

    if (msg == 'q') {

      analogWrite(spd1_1, 255);
      analogWrite(spd1_2, 255);
      analogWrite(spd2_1, 255);
      analogWrite(spd2_2, 255);
      msg_spd = msg;

    }

    msg = (char)bluetooth.read();
    if (msg == 'W') {

    isAuto = true;

    }
    
    if (msg == 'w') {

    isAuto = false;
    msg = msg_spd;

    }
    if (isAuto == true) {
    lineGO();
    }
    
    

  }

}
