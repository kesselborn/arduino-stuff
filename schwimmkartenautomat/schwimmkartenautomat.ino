 
#include <Servo.h>  //add '<' and '>' before and after servo.h
 
int servoPin = 6;

int potpin = 0;
int ledGelbPin = 8;
int ledRotPin = 10;
int knopfPin = 11;
int potentiometer = 5;

int speakerPin = 9;
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 30;
Servo servo; 

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}


void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(ledGelbPin, OUTPUT);
  pinMode(ledRotPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(knopfPin, INPUT);
  servo.attach(servoPin);
  servo.write(180);

  Serial.println("hallo");
}

int knopfState = LOW;
int gelbeLedState = LOW;

void loop() {
  tempo = analogRead(potentiometer) / 5;
  Serial.println(tempo*10);

  int pot = analogRead(potpin);
  int knopf = digitalRead(knopfPin);
  if(knopf == LOW) {
    servo.write(180);
    knopfState = knopfState == HIGH ? LOW : HIGH;
    digitalWrite(ledRotPin, knopfState);
    
    for (int i = 0; i < length; i++) {
      if (notes[i] == ' ') {
        delay(beats[i] * tempo); // rest
      } else {
        playNote(notes[i], beats[i] * tempo);
      }

      // pause between notes
      delay(tempo / 2);
    }
  }

  if(knopfState == HIGH) {
    servo.write(0);
    gelbeLedState = gelbeLedState == HIGH ? LOW : HIGH;
    digitalWrite(ledGelbPin, gelbeLedState);
    delay(500);
  } 

  if(pot > 300 && knopfState == LOW) {
    digitalWrite(ledGelbPin, HIGH);
    playNote(notes[3], beats[3] * tempo);
    delay(1000);
  } else {
    digitalWrite(ledGelbPin, LOW);
  }
  delay(15);
}
