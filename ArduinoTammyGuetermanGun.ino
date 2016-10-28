int led = 13;
int firstRed = 2;
int secondRed = 3;
int thirdRed = 4;
int buzzer = 11;
int button = 8;
int currState = LOW;
int prevState = HIGH;
int iteration = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(firstRed, OUTPUT);
  pinMode(secondRed, OUTPUT);
  pinMode(thirdRed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void gunfire1() {
  for (int i = 0; i < 5; ++i) {
        delay(50);
        gunfire2();
        delay(50);
      }
}

void gunfire2() {
  digitalWrite(firstRed, HIGH);
  digitalWrite(secondRed, HIGH);
  digitalWrite(thirdRed, HIGH);
  for (int i=1;i<2000;i+=15) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(i);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(i);
  }
  digitalWrite(firstRed, LOW);
  digitalWrite(secondRed, LOW);
  digitalWrite(thirdRed, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  currState = digitalRead(button);
  if (currState == 1){
    digitalWrite(firstRed+iteration, HIGH);
    delay(1000);
    ++iteration;
    if (iteration == 3) {
      gunfire1();
      noTone(buzzer);
      digitalWrite(firstRed, LOW);
      digitalWrite(secondRed, LOW);
      digitalWrite(thirdRed, LOW);
      iteration = 0;
      delay(1000);
    }
  }
  else {
    digitalWrite(firstRed, LOW);
    digitalWrite(secondRed, LOW);
    digitalWrite(thirdRed, LOW);
    iteration = 0;
    analogWrite(buzzer, 0);
  }
  prevState = currState;

}
