#include "infrared_distance_sensor.h"
#include <Servo.h>

const int servo_pin = 9;
const int infrared_distance_sensor_pin = A0;

const float HIT_DISTANCE = 15;
const int UP_POSITION = 0;
const int DOWN_POSITION = 100;

Servo servo;
infrared_distance_sensor infrared_distance_sensor(infrared_distance_sensor_pin);

void setup() {
   Serial.begin(115200);
   servo.attach(9);
   servo.write(UP_POSITION);
}

void loop() {
  const int distance = infrared_distance_sensor.read_distance();
  Serial.println(distance);
  if (distance < HIT_DISTANCE)
    servo.write(DOWN_POSITION);
  else
    servo.write(UP_POSITION);
  delay(50);
}
