#include <Servo.h>
Servo servoX;
Servo servoY;
Servo servoZ;
int ButtonU = 52;
int ButtonD = 48;
int ButtonS = 46;
int ButtonA = 50;
int ButtonW = 44;
int E = 7;

void InitZ() {
  while (digitalRead(7) == HIGH) {
    servoZ.write(0);
  }
  servoZ.write(90);
}

void setup() {
  servoX.attach(11);
  servoY.attach(12);
  servoZ.attach(13);
  servoX.write(90);
  servoY.write(90);
  servoZ.write(90);
  pinMode(ButtonU, INPUT_PULLUP); // U
  pinMode(ButtonD, INPUT_PULLUP); // D
  pinMode(ButtonS, INPUT_PULLUP); // S
  pinMode(ButtonA, INPUT_PULLUP); // A
  pinMode(ButtonW, INPUT_PULLUP); // W
  pinMode(E, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  InitZ();
}

void loop() {
  if (digitalRead(ButtonW) == LOW ) {
    servoY.write(180);
  } else if (digitalRead(ButtonS) == LOW ) {
    servoY.write(0);
  } else {
    servoY.write(90);
  }
  if (digitalRead(ButtonA) == LOW ) {
    servoX.write(180);
  } else if (digitalRead(ButtonD) == LOW ) {
    servoX.write(0);
  } else {
    servoX.write(90);
  }

  if (digitalRead(ButtonU) == LOW) {
    servoZ.write(160);
    delay(2200);
    InitZ();
  }
}
