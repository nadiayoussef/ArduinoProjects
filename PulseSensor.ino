
/*  PulseSensor™ Starter Project   http://www.pulsesensor.com
 *   
*/


//  Variables
int PulseSensorPurplePin = A5;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0


int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;            // Determine which Signal to "count as a beat", and which to ingore. 


// The SetUp Function:
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);         // pin that will blink to your heartbeat!
   Serial.begin(9600);         // Set's up Serial Communication at certain speed.
   Serial.println("Start of program");
   
}

// The Main Loop Function
void loop() {

  int signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value. 
                                              // Assign this value to the "Signal" variable.
   
   if(signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.  
     Serial.println("BEAT! " + String(signal));   
   } else {
      Serial.println(String(signal));   

   }


delay(10);
   
   
}



