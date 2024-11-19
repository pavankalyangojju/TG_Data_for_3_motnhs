 
int motor1_in1 = 8;
int motor1_in2 = 9;

 
int motor2_in3 = 10;
int motor2_in4 = 11;

const int trigPin = 15;
const int echoPin = 14;
int distance;
long duration;

void setup() {
  pinMode(23, INPUT_PULLUP);
  pinMode(motor1_in1, OUTPUT);
  pinMode(motor1_in2, OUTPUT);

 
  pinMode(motor2_in3, OUTPUT);
  pinMode(motor2_in4, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
 while (digitalRead(23)) {
    delay(10);
  }
  Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

Serial.println(distance);
if(distance >5){
   
    
    digitalWrite(motor1_in1, HIGH);
    digitalWrite(motor1_in2, LOW);

    digitalWrite(motor2_in3, HIGH);
    digitalWrite(motor2_in4, LOW);
  }
  if(distance <10){
 

    digitalWrite(motor1_in1, LOW);
    digitalWrite(motor1_in2, LOW);

    digitalWrite(motor2_in3, LOW);
    digitalWrite(motor2_in4, LOW);
    delay(1000);

    digitalWrite(motor1_in1, LOW);
    digitalWrite(motor1_in2, HIGH);

    digitalWrite(motor2_in3, LOW);
    digitalWrite(motor2_in4, HIGH);

    delay(300);
    
    digitalWrite(motor1_in1, LOW);
    digitalWrite(motor1_in2, HIGH);

    digitalWrite(motor2_in3, HIGH);
    digitalWrite(motor2_in4, LOW);

    


    delay(300);
  }
   

}
