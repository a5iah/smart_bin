// ---------------------------------------------------------------- //
// Smart Bin using Ultrasoninc Sensor HC-SR04
// written by Asiah Sallehuddin
// Using HC-SR04 Module
// Tested on 17 September 2021
// ---------------------------------------------------------------- //

#define pinLow 9 //attach pin D9 Arduino to LED Green
#define pinMid 10 //attach pin D10 Arduino to LED Yellow
#define pinHigh 11 //attach pin D11 Arduino to LED Red
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(pinLow, OUTPUT); //Sets the pinLow as an OUTPUT
  pinMode(pinMid, OUTPUT); //Sets the pinMid as an OUTPUT
  pinMode(pinHigh, OUTPUT); //Sets the pinHigh as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Smart Bin"); // print some text in Serial Monitor
  Serial.println("By Asiah");

  blinkled(3,500);
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance>20) {
    digitalWrite(pinLow, HIGH);
    digitalWrite(pinMid, LOW);
    digitalWrite(pinHigh, LOW);
  } else if (distance>10) {
    digitalWrite(pinMid, HIGH);
    digitalWrite(pinHigh, LOW);
  } else{
    digitalWrite(pinHigh, HIGH);
  }
}

void blinkled(int t, int dur){
  for (int i = 0; i<t ; i++){
    digitalWrite(pinLow, HIGH);
    digitalWrite(pinMid, HIGH);
    digitalWrite(pinHigh, HIGH);
    delayMicroseconds(dur);
    digitalWrite(pinLow, LOW);
    digitalWrite(pinMid, LOW);
    digitalWrite(pinHigh, LOW);
    delayMicroseconds(dur);
  }
}
