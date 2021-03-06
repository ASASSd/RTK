#include <SoftwareSerial.h>
SoftwareSerial bluetooth(7, 2);
int IN1_1 = 4; 
int IN2_1 = 5; 
int IN3_1 = 6; 
int IN4_1 = 8; 
int i;
int spd1_1 = 3;
int spd1_2 = 9;
char msg;

void setup() {
  //Serial.begin(115200);
  bluetooth.begin(9600);
  pinMode(IN1_1, OUTPUT);
  pinMode(IN2_1, OUTPUT);
  pinMode(IN3_1, OUTPUT);
  pinMode(IN4_1, OUTPUT);
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN4_1, LOW);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  analogWrite(spd1_1, 100);
  analogWrite(spd1_2, 170);
}

void backward() {

  digitalWrite(IN1_1, HIGH);;
  delay(45);
  digitalWrite(IN1_1, LOW);

}

void forward() {

  digitalWrite(IN2_1, HIGH);
  delay(45);
  digitalWrite(IN2_1, LOW);
  
}

void right() {

  digitalWrite(IN3_1, HIGH);
  delay(45);
  digitalWrite(IN3_1, LOW);

}

void left() {
  
  digitalWrite(IN4_1, HIGH);
  delay(45);
  digitalWrite(IN4_1, LOW);
  
}

void loop() {

  if (bluetooth.available()) {
    msg = (char)bluetooth.read();
    //Serial.print("message=");
    // L-Serial.println(msg);
    digitalWrite(IN1_1, LOW);
    digitalWrite(IN2_1, LOW);
    digitalWrite(IN3_1, LOW);
    digitalWrite(IN4_1, LOW);
    delay(1);
    if (msg == 'F') {

      forward();

    }

    if (msg == 'B') {

      backward();

    }
     if (msg == 'R') {

      right();
      //Serial.println("Right trigger");
    }
     if (msg == 'L') {

      left();
      //Serial.println("Left trigger");
    }

    if (msg == '0') {

      analogWrite(spd1_1, 0);
      analogWrite(spd1_2, 0);

    }

    if (msg == '1') {

      analogWrite(spd1_1, 100);
      analogWrite(spd1_2, 100);

    }

    if (msg == '2') {

      analogWrite(spd1_1, 160);
      analogWrite(spd1_2, 160);

    }

    if (msg == '3') {

      analogWrite(spd1_1, 170);
      analogWrite(spd1_2, 170);

    }

    if (msg == '4') {

      analogWrite(spd1_1, 180);
      analogWrite(spd1_2, 180);

    }

    if (msg == '5') {

      analogWrite(spd1_1, 190);
      analogWrite(spd1_2, 190);

    }

    if (msg == '6') {

      analogWrite(spd1_1, 200);
      analogWrite(spd1_2, 200);
    }

    if (msg == '7') {

      analogWrite(spd1_1, 210);
      analogWrite(spd1_2, 210);

    }

    if (msg == '8') {

      analogWrite(spd1_1, 220);
      analogWrite(spd1_2, 220);

    }

    if (msg == '9') {
      
      analogWrite(spd1_1, 230);
      analogWrite(spd1_2, 230);

    }

    if (msg == 'q') {

      analogWrite(spd1_1, 255);
      analogWrite(spd1_2, 255);

    }

  }

}
