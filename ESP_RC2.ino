#include "BluetoothSerial.h" // Bluetooth library

BluetoothSerial SerialBT; // Create Bluetooth object

// Motor driver pins
#define R_EN   25  // Right enable
#define L_EN   26  // Left enable
#define R_EN2  33  // Right enable 2
#define L_EN2  32  // Left enable 2
#define R_PWM  27  // Right PWM
#define R_PWM2 18  // Right PWM 2
#define L_PWM  14  // Left PWM
#define L_PWM2 19  // Left PWM 2

void setupPins() {
  pinMode(R_EN, OUTPUT);  // Set pin as output
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN2, OUTPUT);
  pinMode(L_EN2, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);

  digitalWrite(R_EN, HIGH);  // Enable motor driver
  digitalWrite(L_EN, HIGH);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH);
}

void moveForward() {  // Move forward
  analogWrite(R_PWM, 255);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 255);
  analogWrite(L_PWM2, 0);
  Serial.println("Forward");
}

void moveBackward() {  // Move backward
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 255);
  analogWrite(R_PWM2, 0);
  analogWrite(L_PWM2, 255);
  Serial.println("Backward");
}

void moveLeft() {  // Turn left
  analogWrite(R_PWM, 255);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 50);
  analogWrite(L_PWM2, 0);
  Serial.println("Left");
}

void moveRight() {  // Turn right
  analogWrite(R_PWM, 50);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 255);
  analogWrite(L_PWM2, 0);
  Serial.println("Right");
}

void moveLeftF(){  // Spin left
  analogWrite(R_PWM, 255);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 0);
  analogWrite(L_PWM2, 255);
}

void moveRightF() {  // Spin right
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 255);
  analogWrite(R_PWM2, 255);
  analogWrite(L_PWM2, 0);
  Serial.println("Right");
}

void stopMotors() {  // Stop all motors
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM2, 0);
  analogWrite(L_PWM2, 0);
  Serial.println("Stop");
}

void setup() {
  Serial.begin(115200);  // Start serial
  setupPins();           // Setup motor pins

  SerialBT.begin("ESP32_ROBOT");  // Start Bluetooth
  Serial.println("Bluetooth started. Pair and send commands:");
  Serial.println("F=Forward, B=Backward, L=Left, R=Right, S=Stop");
}

void loop() {
  if (SerialBT.available()) {  // Check Bluetooth input
    char command = SerialBT.read();  // Read command

    switch (command) {  // Match command
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
