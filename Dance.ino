// Allows us to access the Servo header library (to operate with the Servo motor)
#include <Servo.h>

unsigned long previousMillis = 0;
const long interval = 500;
int beatCount;

// Input and Output pins
int analogPin = A0;     // KY-037 analog interface
int motorPin1 = 7;      // Pin to control the servo motor
int motorPin2 = 9;      // Pin to control the servo motor
int motorPin3 = 5;      // Pin to control the servo motor

int threshold = 168;    // Adjust this threshold based on environment

Servo motor1;          // Servo motor object
Servo motor2;
Servo motor3;

// Numbers to represent each state
const int slow = 0; // under 60bpm
const int med = 1;
const int fast = 2; // over 130bpm

void setup() {
  pinMode(analogPin, INPUT);      // Set sound sensor analog pin as input
  motor1.attach(motorPin1);       // Initialize motor1 on motorPin1
  motor2.attach(motorPin2);       // Initialize motor2 on motorPin2
  motor3.attach(motorPin3);       // Initialize motor3 on motorPin3

  Serial.begin(9600);             // Begin Serial communication
  Serial.println("Connected successfully.");

  beatCount = 0;

}

void loop() {

  unsigned long currentMillis = millis();

  int val = analogRead(analogPin);  // Read sound level from sensor
  Serial.println(val);              // Output the sound value for calibration

  if (val >= threshold) {  // If sound level exceeds threshold {
    beatCount++;
    showBeat();
  }



  int bpm = NULL;
  // How many beats have occured in the last 5 seconds?
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Serial.print("Beat count: ");
    Serial.println(beatCount);
    float short_int = ((interval / 100.0) / 60.0);

    if(beatCount <= short_int * 60) {
      bpm = slow;
    }
    else if(beatCount >= short_int * 130) {
      bpm = fast;
    }
    else {
      bpm = med;
    }
    beatCount = 0;
  }

  // Move the motor according to the bpm speed
  switch(bpm) {
    // Slow 
    case slow:
     moveMotor(10);
     break;

    // Medium
    case med:
     moveMotor(5);
     break;

    // Fast
    case fast:
     moveMotor(1);
     break;

     default:
     break;

  }


void moveMotor(int speed) {
  for (int pos = 0; pos <= 90; pos++) {
    motor1.write(pos);
    motor2.write(pos);
    motor3.write(pos);
    delay(speed);
  }

  for (int pos = 90; pos >= 0; pos--) {
    motor1.write(pos);
    motor2.write(pos);
    motor3.write(pos);
    delay(speed);
  }
};


void showBeat() {
  Serial.println("     ||     ");
  Serial.println("    ||||    ");
  Serial.println("  ||||||||  ");
  Serial.println("||||||||||||");
  Serial.println("  ||||||||  ");
  Serial.println("    ||||    ");
  Serial.println("     ||     ");
};



