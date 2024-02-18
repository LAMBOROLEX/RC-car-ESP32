// https://randomnerdtutorials.com/esp32-dc-motor-l298n-motor-driver-control-speed-direction/
// https://www.youtube.com/watch?v=IuyBaxSqQ50

// Web: https://randomnerdtutorials.com/esp32-websocket-server-sensor/
// Filesystem: https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/

#include <Arduino.h>
#include <WiFi.h>

#define WIFI_SSID "WIFI NAME"
#define WIFI_PSWD "WIFI PASSWORD"

void initWIFI() {
  /*.Initialize Server */
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PSWD);

  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
  }
}


void setup() {
  Serial.begin(115200);
  

  initWIFI();
  
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  
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
