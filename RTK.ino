                                                                                                                                                                             #include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial bluetooth(52, 53);
Servo claw;
int IN1_1 = 8; //правый задний вперед
int IN2_1 = 9; //правый задний назад
int IN3_1 = 10; //правый передний вперед
int IN4_1 = 11; //правый передний назад
int IN1_2 = 47; //левый задний вперед
int IN2_2 = 45; //левый задний назад
int IN3_2 = 43; //левый передний вперед
int IN4_2 = 41; //левый передний назад
int IN3_3 = 25;
int IN4_3 = 51;
int i;
int pir1 = 30;
int pir2 = 31;
int spd1_1 = 4;
int spd2_1 = 5;
int spd1_2 = 6;
int spd2_2 = 7;
char msg;
int angle = 90;

void setup() {
  //Serial.begin(115200);
  bluetooth.begin(9600);
  for (i = 41; i <= 47; i++) {

    pinMode(i, OUTPUT);

  }
  claw.attach(49);
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN1_2, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, LOW);
  digitalWrite(IN4_2, LOW);
  pinMode(IN3_3, OUTPUT);
  pinMode(IN4_3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  analogWrite(spd1_1, 100);
  analogWrite(spd1_2, 100);
  analogWrite(spd2_1, 100);
  analogWrite(spd2_2, 100);
  digitalWrite(IN3_3, LOW);
  digitalWrite(IN4_3, LOW);
}

void forward() {

  digitalWrite(IN2_1, HIGH);
  digitalWrite(IN4_1, HIGH);
  digitalWrite(IN1_2, HIGH);
  digitalWrite(IN3_2, HIGH);
  delay(45);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN1_2, LOW);
  digitalWrite(IN3_2, LOW);

}

void backward() {

  digitalWrite(IN1_1, HIGH);
  digitalWrite(IN3_1, HIGH);
  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN4_2, HIGH);
  delay(45);
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN4_2, LOW);

}

void left() {

  digitalWrite(IN1_1, HIGH);
  digitalWrite(IN3_1, HIGH);
  digitalWrite(IN1_2, HIGH);
  digitalWrite(IN3_2, HIGH);
  delay(45);
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN1_2, LOW);
  digitalWrite(IN3_2, LOW);

}

void right() {

  digitalWrite(IN2_1, HIGH);
  digitalWrite(IN4_1, HIGH);
  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN4_2, HIGH);
  delay(45);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN4_2, LOW);

}

void clawcompress(){
  digitalWrite(IN3_3, HIGH);
  digitalWrite(IN4_3, LOW);
  delay(45);
  digitalWrite(IN3_3, LOW);
  digitalWrite(IN4_3, LOW);
}

void clawdecompress(){
  digitalWrite(IN3_3, LOW);
  digitalWrite(IN4_3, HIGH);
  delay(45);
  digitalWrite(IN4_3, LOW);
  digitalWrite(IN3_3, LOW);
}

void loop() {

  if (bluetooth.available()) {

    msg = (char)bluetooth.read();
    //Serial.println(msg);
    digitalWrite(IN1_1, LOW);
    digitalWrite(IN2_1, LOW);
    digitalWrite(IN3_1, LOW);
    digitalWrite(IN4_1, LOW);
    digitalWrite(IN1_2, LOW);
    digitalWrite(IN2_2, LOW);
    digitalWrite(IN3_2, LOW);
    digitalWrite(IN4_2, LOW);
    delay(1);
    if (msg == 'F') {

      forward();

    }

    if (msg == 'B') {

      backward();

    }

    if (msg == 'R') {

      left();

    }

    if (msg == 'L') {

      right();

    }

    if (msg == 'G') {

      claw.write(angle);
      angle = angle + 10;

    }

    if (msg == 'I') {

      claw.write(angle);
      angle = angle - 10;

    }

    if (msg == 'W') {

      digitalWrite(pir1, HIGH);
      digitalWrite(pir2, HIGH);

    }

    if (msg == 'w') {

      digitalWrite(pir1, LOW);
      digitalWrite(pir2, LOW);

    }

    if (msg == '0') {

      analogWrite(spd1_1, 0);
      analogWrite(spd1_2, 0);
      analogWrite(spd2_1, 0);
      analogWrite(spd2_2, 0);

    }

    if (msg == '1') {

      analogWrite(spd1_1, 100);
      analogWrite(spd1_2, 100);
      analogWrite(spd2_1, 100);
      analogWrite(spd2_2, 100);

    }

    if (msg == '2') {

      analogWrite(spd1_1, 160);
      analogWrite(spd1_2, 160);
      analogWrite(spd2_1, 160);
      analogWrite(spd2_2, 160);

    }

    if (msg == '3') {

      analogWrite(spd1_1, 170);
      analogWrite(spd1_2, 170);
      analogWrite(spd2_1, 170);
      analogWrite(spd2_2, 170);

    }

    if (msg == '4') {

      analogWrite(spd1_1, 180);
      analogWrite(spd1_2, 180);
      analogWrite(spd2_1, 180);
      analogWrite(spd2_2, 180);

    }

    if (msg == '5') {

      analogWrite(spd1_1, 190);
      analogWrite(spd1_2, 190);
      analogWrite(spd2_1, 190);
      analogWrite(spd2_2, 190);

    }

    if (msg == '6') {

      analogWrite(spd1_1, 200);
      analogWrite(spd1_2, 200);
      analogWrite(spd2_1, 200);
      analogWrite(spd2_2, 200);
    }

    if (msg == '7') {

      analogWrite(spd1_1, 210);
      analogWrite(spd1_2, 210);
      analogWrite(spd2_1, 210);
      analogWrite(spd2_2, 210);

    }

    if (msg == '8') {

      analogWrite(spd1_1, 220);
      analogWrite(spd1_2, 220);
      analogWrite(spd2_1, 220);
      analogWrite(spd2_2, 220);

    }

    if (msg == '9') {

      analogWrite(spd1_1, 230);
      analogWrite(spd1_2, 230);
      analogWrite(spd2_1, 230);
      analogWrite(spd2_2, 230);

    }

    if (msg == 'q') {

      analogWrite(spd1_1, 255);
      analogWrite(spd1_2, 255);
      analogWrite(spd2_1, 255);
      analogWrite(spd2_2, 255);

    }

    if (msg == 'H') {

     clawcompress();

    }

    if (msg == 'J') {

      clawdecompress();

    }
  }


}
