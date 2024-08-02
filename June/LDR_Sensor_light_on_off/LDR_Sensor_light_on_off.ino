
#define Sensor 8
#define RELAY_PIN 7


void setup() {
  pinMode(Sensor, INPUT);
  pinMode(13,OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
}
void loop() {
int status_sensor = digitalRead(Sensor);
if (status_sensor ==1)
{
digitalWrite(13, HIGH);
digitalWrite(RELAY_PIN, LOW);
}
else 
{
digitalWrite(13, LOW);
digitalWrite(RELAY_PIN, HIGH);
}
delay(100);

}
