int schritte = 2;
int geschwindigkeit = 500;
float schritte_pro_grad = 4.5;
int schrittlaenge = 100;
int delay_duration = 5;

int motor_rechts[4] = {4, 5, 6, 7};

void bereite_motor_rechts_vor() {
  pinMode(motor_rechts[0], OUTPUT);
  pinMode(motor_rechts[1], OUTPUT);
  pinMode(motor_rechts[2], OUTPUT);
  pinMode(motor_rechts[3], OUTPUT);
}


int motor_links[4] = {8, 9, 10, 11};

void bereite_motor_links_vor() {
  pinMode(motor_links[0], OUTPUT);
  pinMode(motor_links[1], OUTPUT);
  pinMode(motor_links[2], OUTPUT);
  pinMode(motor_links[3], OUTPUT);
}

int ledPin = 2;
void setup() {
  bereite_motor_rechts_vor();
  bereite_motor_links_vor();
  pinMode(ledPin, OUTPUT);
}

void vorwaerts() {
  bewegen(motor_rechts, motor_links);
}

void rueckwaerts() {
  bewegen(motor_links, motor_rechts);
}

void setze_motor_pins(int motor[4], int pin_0, int pin_1, int pin_2, int pin_3) {
  digitalWrite(motor[0], pin_0 ? HIGH : LOW);
  digitalWrite(motor[1], pin_1 ? HIGH : LOW);
  digitalWrite(motor[2], pin_2 ? HIGH : LOW);
  digitalWrite(motor[3], pin_3 ? HIGH : LOW);
}

void bewegen(int motor1[4], int motor2[4]) {
  ///////////////////////////// 1
  setze_motor_pins(motor1, true, false, false, false);
  setze_motor_pins(motor2, false, false, false, true);
  delay(delay_duration);

  ///////////////////////////// 2
  setze_motor_pins(motor1, false, true, false, false);
  setze_motor_pins(motor2, false, false, true, false);
  delay(delay_duration);

  ///////////////////////////// 3
  setze_motor_pins(motor1, false, false, true, false);
  setze_motor_pins(motor2, false, true, false, false);
  delay(delay_duration);

  ///////////////////////////// 4
  setze_motor_pins(motor1, false, false, false, true);
  setze_motor_pins(motor2, true, false, false, false);

  delay(delay_duration);
}

void links_drehen() {
  ///////////////////////////// 1
  setze_motor_pins(motor_rechts, false, false, false, true);
  setze_motor_pins(motor_links, false, false, false, true);
  delay(delay_duration);

  ///////////////////////////// 2
  setze_motor_pins(motor_rechts, false, false, true, false);
  setze_motor_pins(motor_links, false, false, true, false);
  delay(delay_duration);

  ///////////////////////////// 3
  setze_motor_pins(motor_rechts, false, true, false, false);
  setze_motor_pins(motor_links, false, true, false, false);
  delay(delay_duration);

  ///////////////////////////// 4
  setze_motor_pins(motor_rechts, true, false, false, false);
  setze_motor_pins(motor_links, true, false, false, false);
  delay(delay_duration);
}

void rechts_drehen() {
  ///////////////////////////// 1
  setze_motor_pins(motor_rechts, true, false, false, false);
  setze_motor_pins(motor_links, true, false, false, false);
  delay(delay_duration);

  ///////////////////////////// 2
  setze_motor_pins(motor_rechts, false, true, false, false);
  setze_motor_pins(motor_links, false, true, false, false);
  delay(delay_duration);

  ///////////////////////////// 3
  setze_motor_pins(motor_rechts, false, false, true, false);
  setze_motor_pins(motor_links, false, false, true, false);
  delay(delay_duration);

  ///////////////////////////// 4
  setze_motor_pins(motor_rechts, false, false, false, true);
  setze_motor_pins(motor_links, false, false, false, true);
  delay(delay_duration);
}

void start_signal() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
}

void end_signal() {
  for(;;) {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
  }
}

bool running = false;
void loop() {
  if(!running) {
    running = true;
    start_signal();
    schritte = 3;

    for (int j = 0; j < (schritte * schrittlaenge); j++) {
      vorwaerts();
    }
     for (int i = 0; i < (90 * schritte_pro_grad); i++) {
       rechts_drehen();
     }
    for (int j = 0; j < (schritte * schrittlaenge); j++) {
      rueckwaerts();
    }
    for (int i = 0; i < (90 * schritte_pro_grad); i++) {
      links_drehen();
    }
    end_signal();
  }
  //  exit(0);
}
