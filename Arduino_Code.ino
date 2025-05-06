// Define pins for the ultrasonic sensor
const int trigPin = 3;  // Trigger pin
const int echoPin = 2;  // Echo pin

// Variables to store distance
long duration;
int distance;

void setup() {
  // Set up serial communication for debugging
  Serial.begin(9600);

  // Set the trigger pin as output and the echo pin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10µs HIGH pulse to the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin for the duration of the pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Add a short delay before the next measurement
  delay(500);
}
