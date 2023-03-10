#include <Stepper.h>
#define button_pin 4

const int stepsPerRevolution = 2048;  

#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 22

Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  myStepper.setSpeed(5);
  Serial.begin(115200);
}

void loop() {
  int buttonValue = digitalRead(button_pin);
  if (buttonValue == 0) {
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
    delay(1000);
  }
}
