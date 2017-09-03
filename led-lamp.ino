#include <math.h>

int led = 9;
int lightSensor = 4;
int moveSensor = 3;

short darkness = 0;
unsigned long fadeInTime = 0L;
unsigned long fadeOutTime = 0L;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(moveSensor, INPUT);
  pinMode(lightSensor, INPUT);

  // Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  unsigned long t = millis();
  int moving = digitalRead(moveSensor);

  // Serial.print(moving);
  // Serial.print(" ");
  // Serial.println(darkness);

  if (moving && !fadeInTime && darkness) {
    fadeInTime = t;
    fadeOutTime = 0L;
  }

  if (!moving && fadeInTime) {
    fadeInTime = 0L;
    fadeOutTime = t;
    //analogWrite(led, 256); // not 0, see http://forum.arduino.cc/index.php?topic=360468
    //delay(20);
    //digitalWrite(led, 0);
  }

  if (fadeOutTime) {
    int val = min(pow(1.0005544, max(10000.0 - (t - fadeOutTime) * 10.0, 1)), 255);
    analogWrite(led, val - 1);        
  }

  if (fadeInTime) {
    int val = min(pow(1.0005544, min((t - fadeInTime) * 10.0, 10000.0)), 255);
    analogWrite(led, val);    
  }

//  if (t - fadeInTime > 1000L) {
//    fadeInTime = 0;
//  }
//
//  if (t - fadeOutTime > 1000L) {
//    fadeOutTime = 0;
//  }

  if (t - fadeOutTime > 1000L) {
    darkness = digitalRead(lightSensor);
  }
}
