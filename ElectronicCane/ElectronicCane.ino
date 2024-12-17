/*
  Rewritten by KamarulUkail 2024 | TERMZL0ckd0wn
  Project source : 1. https://termz.eu.org/projects/TE-BM (BM)
                  2. https://termz.eu.org/projects/TE-EN (EN)
                  2.https://github.com/TERMZL0ckd0wn/Tongkat-Elektronik (BM/EN)
*/

// Declares variables for input and output pins
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 7;
const int waterSensor = 8;

// Declaring a couple of variables that can be changed later
long duration;
int distance;
int safeDistance;


void setup() { // Part that only runs once

  // Tells the Arduino that trigPin & buzzer are OUTPUT pins
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  // Tells the Arduino that echoPin & waterSensor are INPUT pins
  pinMode(echoPin, INPUT);
  pinMode(waterSensor, INPUT);

  // Serial connection for checking and adjusting the ultrasonic sensor
  Serial.begin(9600);

}

void loop() { // Part that runs forever

  // Clears trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1); // 1000 microseconds = 1 second

  // Tells the Arduino to pulse the trigPin every 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);



  // Reads the pulses received and stores the value for distance calculation
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance with the duration of the pulse emmit and receive
  distance = duration * 0.034/2; // duration * speedOfSound / 2

  // Sets the safeDistance as same value as distance variable
  safeDistance = distance;



  // If the safeDistance is below or the same as 20cm or the water sensor detects there is water...
  if (safeDistance <= 20 || digitalRead(waterSensor) == HIGH) {
    digitalWrite(buzzer, HIGH); // Buzzer will beep
  } else { // Other than that ...
    digitalWrite(buzzer, LOW); // Buzzer will be silent
  }



  // Write the current distance through serial
  Serial.print("Current Distance: ");
  Serial.println(distance);

  // End

}
