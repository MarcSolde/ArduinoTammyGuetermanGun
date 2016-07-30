//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// The Unnamed Circuit
// 
// Made by f613300 f613300
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/2469664-the-unnamed-circuit

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
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

void test_PWM_all() {
  for (int i= 0; i <= 255; ++i) {
        analogWrite(buzzer,i);
        Serial.print("Valor de i: ");Serial.println(i);
        delay(100);
      }
}

void test_PWM_range(int i, int j){
  analogWrite(buzzer, i);
  delay(500);
  ++i;
  while(i < j) {
        analogWrite(buzzer,i);
        Serial.print("Valor de i: ");Serial.println(i);
        //delay(100);
        i=i+2;
      }
}

void gunfire1() {
  for (int i = 0; i < 5; ++i) {
        //noTone(buzzer);
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
    //if (iteration == 0) tone(buzzer, 100);
    delay(1000);
    ++iteration;
    if (iteration == 3) {
      //tone(buzzer, 700,200);
      //test_PWM_all();
      //test_PWM_range(135, 150);
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
    //noTone(buzzer);
    analogWrite(buzzer, 0);
  }
  prevState = currState;
  
}
