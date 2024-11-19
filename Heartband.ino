unsigned long previousMillis = 0;
const long interval = 5000;
const int sensorPin = A5;
const int motorPin = 6;
const int threshold = 550; // A heartbeat is detected if threshold is hit
int pulse;

#include <VibrationMotor.h>

void setup() {
  Serial.begin(115200); // Higher baud because the default is too low for the sensor
}

void loop() {
  VibrationMotor vibe(motorPin);
  pulse = analogRead(sensorPin);
  double count = 0; // To keep track of the frequency of beats

  unsigned long currentMillis = millis();
   if(currentMillis - previousMillis >= interval) { // 5 second intervals

    if(pulse > threshold){
     Serial.println("Sensor value: " + String(pulse));
     count++; // Records total number of beats in this 5 second interval
    }

   }

   if (count > 8.33) { // 8.33 beats in 5 seconds equates to about 100 beats per minute, which is above the average resting rate
    Serial.println("Heart rate is above average - remember to breathe!");
    vibe.on();
    delay(10000); // Vibrates for 10 seconds
   }
   vibe.off();

}



