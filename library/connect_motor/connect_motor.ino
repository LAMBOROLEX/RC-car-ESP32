// https://randomnerdtutorials.com/esp32-dc-motor-l298n-motor-driver-control-speed-direction/
// https://www.youtube.com/watch?v=IuyBaxSqQ50

// Web: https://randomnerdtutorials.com/esp32-websocket-server-sensor/
// Filesystem: https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/

#include <Arduino.h>

#define MOTOR_PIN1 27
#define MOTOR_PIN2 26
#define ENABLE_PIN1 14

#define MOTOR_PIN3 18
#define MOTOR_PIN4 19
#define ENABLE_PIN2 33

#define PWM_FREQ 30000
#define PWM_CHANNEL 0
#define PWM_RESOLUTION 8
int dutyCycle = 255;
unsigned int moveStatus = 0; // 0: stop, 1: forward, 2: none, 3: backward, 4: none

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
// JSONVar readings;

const char* PARAM_MESSAGE = "This is a web server";

}


void initMotors() {
  // sets the pins as outputs:
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(ENABLE_PIN1, OUTPUT);

  pinMode(MOTOR_PIN3, OUTPUT);
  pinMode(MOTOR_PIN4, OUTPUT);
  pinMode(ENABLE_PIN2, OUTPUT);

  // configure LED PWM functionalitites
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ENABLE_PIN1, PWM_CHANNEL);
  ledcAttachPin(ENABLE_PIN2, PWM_CHANNEL);
}

void setup() {
  Serial.begin(115200);
  // Serial.print("Testing DC Motor...");

  
  initMotors();
  
}

void loop() {
  // Serial.println(moveStatus);

  switch(moveStatus) {
    case 0:
      digitalWrite(MOTOR_PIN1, LOW);
      digitalWrite(MOTOR_PIN2, LOW);
      digitalWrite(MOTOR_PIN3, LOW);
      digitalWrite(MOTOR_PIN4, LOW);
      break;
    case 1: // Up
      digitalWrite(MOTOR_PIN1, LOW);
      digitalWrite(MOTOR_PIN2, HIGH);
      digitalWrite(MOTOR_PIN3, LOW);
      digitalWrite(MOTOR_PIN4, HIGH);
      break;
    case 2: // Left
      digitalWrite(MOTOR_PIN1, LOW);
      digitalWrite(MOTOR_PIN2, HIGH);
      digitalWrite(MOTOR_PIN3, HIGH);
      digitalWrite(MOTOR_PIN4, LOW);
      break;
    case 3: // Down
      digitalWrite(MOTOR_PIN1, HIGH);
      digitalWrite(MOTOR_PIN2, LOW);
      digitalWrite(MOTOR_PIN3, HIGH);
      digitalWrite(MOTOR_PIN4, LOW);
      break;
    case 4: // Right
      digitalWrite(MOTOR_PIN1, HIGH);
      digitalWrite(MOTOR_PIN2, LOW);
      digitalWrite(MOTOR_PIN3, LOW);
      digitalWrite(MOTOR_PIN4, HIGH);
      break;
  }


  // Move DC motor forward with increasing speed
  // digitalWrite(MOTOR_PIN1, HIGH);
  // digitalWrite(MOTOR_PIN2, LOW);
  // while (dutyCycle <= 255){
  //   ledcWrite(PWM_CHANNEL, dutyCycle);
  //   Serial.print("Forward with duty cycle: ");
  //   Serial.println(dutyCycle);
  //   dutyCycle = dutyCycle + 5;
  //   delay(500);
  // }
  // dutyCycle = 200;
}
