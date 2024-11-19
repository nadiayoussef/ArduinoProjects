// #include <Keyboard.h> 


// LED pins
const int work = 12;
const int fuel = 11;
const int move = 10;
const int sleep = 9;
const int sani = 8;

const int sensor = A0;

/*

work = w
fuel = f
move = m
sleep = s
sani/bathroom = b
off = o

*/


int state = 0;
char inChar;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(work, OUTPUT);
  pinMode(fuel, OUTPUT);
  pinMode(move, OUTPUT);
  pinMode(sleep, OUTPUT);
  pinMode(sani, OUTPUT);

   // open the serial port:
  Serial.begin(9600);

  // initialize control over the keyboard:
  // Keyboard.begin();
}


void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    // state = Serial.read(); // Reads the data from the serial port
    inChar = Serial.read();
 }
 int sensorVal = 0;
 sensorVal = analogRead(sensor);
 Serial.println(sensorVal);

//  if (state == '1') {
//   digitalWrite(LED_BUILTIN, HIGH); // LED ON
//   state = 0;
//  }
//  else if (state == '0') {
//   allOff();
//  }
//   else if (state == '2') {
//   digitalWrite(work, HIGH); // LED ON
//   digitalWrite(fuel, LOW);
//   digitalWrite(move, LOW);
//   digitalWrite(sleep, LOW);
//   digitalWrite(sani, LOW);
//  }
//  else if (state == '3') {
//   digitalWrite(fuel, HIGH); // LED ON
//   digitalWrite(work, LOW);
//   digitalWrite(move, LOW);
//   digitalWrite(sleep, LOW);
//   digitalWrite(sani, LOW);
//  }
//  else if (state == '4') {
//   digitalWrite(move, HIGH); // LED ON
//   digitalWrite(work, LOW);
//   digitalWrite(fuel, LOW);
//   digitalWrite(sleep, LOW);
//   digitalWrite(sani, LOW);
//  }
//  else if (state == '5') {
//   digitalWrite(sleep, HIGH); // LED ON
//   digitalWrite(work, LOW);
//   digitalWrite(fuel, LOW);
//   digitalWrite(move, LOW);
//   digitalWrite(sani, LOW);
//  }
//  else if (state == '6') {
//   digitalWrite(sani, HIGH); // LED ON
//   digitalWrite(work, LOW);
//   digitalWrite(fuel, LOW);
//   digitalWrite(move, LOW);
//   digitalWrite(sleep, LOW);
//  }

    // char inChar;
    // inChar = Serial.read();

    if(inChar == 'o') {
      allOff();
    }
    else if(inChar == 'w') {
      digitalWrite(work, HIGH); // LED ON
      digitalWrite(fuel, LOW);
      digitalWrite(move, LOW);
      digitalWrite(sleep, LOW);
      digitalWrite(sani, LOW);
    }
    else if(inChar == 'f') {
      digitalWrite(fuel, HIGH); // LED ON
      digitalWrite(work, LOW);
      digitalWrite(move, LOW);
      digitalWrite(sleep, LOW);
      digitalWrite(sani, LOW);
    }
    else if(inChar == 'm') {
      digitalWrite(move, HIGH); // LED ON
      digitalWrite(work, LOW);
      digitalWrite(fuel, LOW);
      digitalWrite(sleep, LOW);
      digitalWrite(sani, LOW);
    }
    else if(inChar == 's') {
      digitalWrite(sleep, HIGH); // LED ON
      digitalWrite(work, LOW);
      digitalWrite(fuel, LOW);
      digitalWrite(move, LOW);
      digitalWrite(sani, LOW);
    }
    else if(inChar == 'b') {
      digitalWrite(sani, HIGH); // LED ON
      digitalWrite(work, LOW);
      digitalWrite(fuel, LOW);
      digitalWrite(move, LOW);
      digitalWrite(sleep, LOW);
    }

}

void allOff() {
  digitalWrite(work, LOW);
  digitalWrite(fuel, LOW);
  digitalWrite(move, LOW);
  digitalWrite(sleep, LOW);
  digitalWrite(sani, LOW);
}


void allOn() {
  digitalWrite(work, HIGH);
  digitalWrite(fuel, HIGH);
  digitalWrite(move, HIGH);
  digitalWrite(sleep, HIGH);
  digitalWrite(sani, HIGH);
}
