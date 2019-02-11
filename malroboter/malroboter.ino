int schritte = 0;
int grad = 0;
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

int motor_stiftheber[4] = {14, 15, 16, 17};

void bereite_motor_stiftheber_vor() {
  pinMode(motor_stiftheber[0], OUTPUT);
  pinMode(motor_stiftheber[1], OUTPUT);
  pinMode(motor_stiftheber[2], OUTPUT);
  pinMode(motor_stiftheber[3], OUTPUT);
}

int geschwindigkeit = 300;
float schritte_pro_grad = 2.985;
int schrittlaenge = 50;
int delay_duration = 5;

int ledPin = 2;
void setup() {
  bereite_motor_rechts_vor();
  bereite_motor_links_vor();
  bereite_motor_stiftheber_vor();
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

void rechts_drehen() {
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

void links_drehen() {
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

void stift_hoch() {
  for(int i=0; i<300; i++) {
    setze_motor_pins(motor_stiftheber, false, false, false, true);
    delay(delay_duration);
    setze_motor_pins(motor_stiftheber, false, false, true, false);
    delay(delay_duration);
    setze_motor_pins(motor_stiftheber, false, true, false, false);
    delay(delay_duration);
    setze_motor_pins(motor_stiftheber, true, false, false, false);
    delay(delay_duration);
 }
}

void stift_runter() {
  for(int i=0; i<300; i++) {
    setze_motor_pins(motor_stiftheber, true, false, false, false);
    delay(delay_duration);
    setze_motor_pins(motor_stiftheber, false, true, false, false);
    delay(delay_duration);
    setze_motor_pins(motor_stiftheber, false, false, true, false);
    delay(delay_duration);
    setze_motor_pins(motor_stiftheber, false, false, false, true);
    delay(delay_duration);
  }
}


bool running = false;
void loop() {
  if(!running) {
    running = true;
    start_signal();
    delay_duration = ((1.0/(1.0*geschwindigkeit))*1000.0)*1;
    
      schritte = 2;
      schritte_pro_grad = 2.98;
      schrittlaenge = 20;
      geschwindigkeit = 300;
    
    stift_runter();
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int j = 0; j < ((1.5 * schritte) * schrittlaenge); j++) {
      rueckwaerts();
    }
    for (int i = 0; i < (90 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    for (int j = 0; j < ((1 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int j = 0; j < (90 * schritte_pro_grad); j++) {
      links_drehen();
    }
    
    for (int j = 0; j < ((1.5 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      rueckwaerts();
    }
    stift_hoch();
    for (int i = 0; i < (90 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    for (int j = 0; j < ((0.5 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int j = 0; j < (90 * schritte_pro_grad); j++) {
      links_drehen();
    }
    
    
    for (int i = 0; i < (20 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    stift_runter();
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    stift_hoch();
    for (int j = 0; j < ((1.5 * schritte) * schrittlaenge); j++) {
      rueckwaerts();
    }
    for (int i = 0; i < (70 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    stift_runter();
    for (int j = 0; j < ((1 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int j = 0; j < (110 * schritte_pro_grad); j++) {
      links_drehen();
    }
    
    for (int j = 0; j < ((1.5 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      rueckwaerts();
    }
    stift_hoch();
    for (int i = 0; i < (110 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    for (int j = 0; j < (0.5 * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int j = 0; j < (90 * schritte_pro_grad); j++) {
      links_drehen();
    }
    
    
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    stift_runter();
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      rueckwaerts();
    }
    for (int i = 0; i < (90 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    for (int j = 0; j < ((1.5 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    stift_hoch();
    for (int j = 0; j < ((0.5 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int j = 0; j < (90 * schritte_pro_grad); j++) {
      links_drehen();
    }
    
    
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    stift_runter();
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      rueckwaerts();
    }
    for (int i = 0; i < (90 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    for (int j = 0; j < ((1.5 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    stift_hoch();
    for (int j = 0; j < ((0.5 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int j = 0; j < (90 * schritte_pro_grad); j++) {
      links_drehen();
    }
    
    
    stift_runter();
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int i = 0; i < (90 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    for (int j = 0; j < ((1.5 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int i = 0; i < (90 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    for (int j = 0; j < ((3 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    for (int i = 0; i < (90 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    for (int j = 0; j < ((1.5 * schritte) * schrittlaenge); j++) {
      vorwaerts();
    }
    stift_hoch();
    for (int j = 0; j < ((2 * schritte) * schrittlaenge); j++) {
      rueckwaerts();
    }
    for (int i = 0; i < (90 * schritte_pro_grad); i++) {
      rechts_drehen();  
    }
    
    end_signal();
  }
}
