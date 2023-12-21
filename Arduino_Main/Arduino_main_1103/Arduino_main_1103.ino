

// int const trigPin = 13;
// int const echoPin = 12;
// int Duration;
// int Distance;

int vac = 7;

// Motor A connections
int enA = 3;
int in1 = 5;
int in2 = 6;
// Motor B connections
int enB = 9;
int in3 = 10;
int in4 = 11;               

int redLED = 12;

bool LED = false;

void setup() {
  Serial.begin(9600);
   
  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);
  // digitalWrite(trigPin, LOW);

  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, LOW);

  pinMode(vac, OUTPUT);
  digitalWrite(vac, LOW);

	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

}

void loop() {
  // digitalWrite(trigPin, HIGH); // 發射超音波
  // delay(10);
  // digitalWrite(trigPin, LOW);
  // Duration = pulseIn(echoPin, HIGH); // 超音波發射到接收的時間
  // Distance = Duration * 0.034 / 2; // 計算距離(cm)
  // Serial.println(Distance);
  stop();
  // vacoff();

  if (Serial.available() > 0) {
    char command = Serial.read();
  

    switch (command) {
      case 'A':
        if(!LED){
          digitalWrite(redLED, HIGH);
          LED = true;
        }else{
          digitalWrite(redLED, LOW);
          LED = false;
        }
        break;
      case '/6556F':
        forward(800);
        break;
      case 'B':
        backward();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':
        stop();
        break;
      case 'V':
        vacon();
        break;
      case 'N':
        vacoff();
        break;
      case 'T':
        digitalWrite(vac, HIGH);
        forward(100);
        delay(200);
        right();
        delay(200);
        break;
    }
    Serial.flush();
  }

}

void forward(int Ftime) {

  analogWrite(enA, 75);
	analogWrite(enB, 75);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

  delay(Ftime);

}

void backward(void) {

  analogWrite(enA, 75);
	analogWrite(enB, 75);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

  delay(300);
}

void left(void) {
  
  analogWrite(enA, 75);
	analogWrite(enB, 75);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

  delay(300);
}

void right(void) {

  analogWrite(enA, 75);
	analogWrite(enB, 75);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

  delay(300);
}

void stop() {
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  
}

void vacon() {

	digitalWrite(vac, HIGH);

  delay(100);

}

void vacoff() {

	digitalWrite(vac, LOW);

}



