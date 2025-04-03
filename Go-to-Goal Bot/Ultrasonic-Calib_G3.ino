// Define pins
#define trigPin 9
#define echoPin 10

// Define variables
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Define pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Wait for sensor to settle
  delay(1000);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure duration of echo pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance
  distance = duration * 0.034 / 2;
  
  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Wait for a moment before measuring again
  delay(500);
}