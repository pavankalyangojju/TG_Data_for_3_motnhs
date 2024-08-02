int RMotor_1 = 2;
int RMotor_2 = 3;
int LMotor_1 = 4;
int LMotor_2 = 5;
void setup() {
  Serial.begin(9600);
  Serial.println("TECHYGUIDE");
  pinMode(RMotor_1, OUTPUT);
  pinMode(RMotor_2, OUTPUT);
  pinMode(LMotor_1, OUTPUT);
  pinMode(LMotor_2, OUTPUT);
 
}

void loop() {
  int irright = digitalRead(12);
  int irleft = digitalRead(11);

  if ( irright == 0 && irleft == 0) {
    Serial.println("F");
    move_forward();
  }
  if (irright == 0 && irleft == 1) {
    Serial.println("R");
    turn_right();
  }
  if ( irright == 1 &&  irleft == 0) {
    Serial.println("L");
    turn_left();
  }
  if ( irright == 1 &&  irleft == 1) {
    Serial.println("S");
    move_stop();
  }
 

}

void move_forward() {
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
}

void move_backward() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, HIGH);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, HIGH);
}
void turn_right() {
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, HIGH);
}
void turn_left() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, HIGH);
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
}

void move_stop() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, LOW);
}
