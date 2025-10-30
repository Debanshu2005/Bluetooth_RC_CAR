#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Motor driver pins
#define R_EN   25
#define L_EN   26
#define R_EN2  33
#define L_EN2  32
#define R_PWM  27
#define R_PWM2 18
#define L_PWM  14
#define L_PWM2 19

void setupPins() {
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN2, OUTPUT);
  pinMode(L_EN2, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);

  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH);
}

void moveForward() {
  analogWrite(R_PWM, 255);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 255);
  analogWrite(L_PWM2, 0);
  Serial.println("Forward");
}

void moveBackward() {
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 255);
  analogWrite(R_PWM2, 0);
  analogWrite(L_PWM2, 255);
  Serial.println("Backward");
}

void moveLeft() {
  analogWrite(R_PWM, 255);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 50);
  analogWrite(L_PWM2, 0);
  Serial.println("Left");
}

void moveRight() {
  analogWrite(R_PWM, 50);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 255);
  analogWrite(L_PWM2, 0);
  Serial.println("Right");
}

void moveLeftF(){
  analogWrite(R_PWM, 255);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 0);
  analogWrite(L_PWM2, 255);
}

void moveRightF() {
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 255);
  analogWrite(R_PWM2, 255);
  analogWrite(L_PWM2, 0);
  Serial.println("Right");
}

void stopMotors() {
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 0);
  analogWrite(L_PWM2, 0);
  Serial.println("Stop");
}

void setup() {
  Serial.begin(115200);
  setupPins();

  // Start Bluetooth
  SerialBT.begin("ESP32_ROBOT");  // Bluetooth name visible on phone
  Serial.println("Bluetooth started. Pair and send commands:");
  Serial.println("F=Forward, B=Backward, L=Left, R=Right, S=Stop");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();

    switch (command) {
      case 'F': moveForward(); break;
      case 'B': moveBackward(); break;
      case 'L': moveLeft(); break;
      case 'R': moveRight(); break;
      case 'S': stopMotors(); break;
      case 'X': moveLeftF(); break;
      case 'Y': moveRightF(); break;
      default:
        Serial.println("Unknown command");
        break;
    }
  }
}