int ledPin1 = 13; // 第一個LED接腳
int ledPin2 = 4; // 第二個LED接腳

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

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT); // 設定LED接腳為輸出
  pinMode(ledPin2, OUTPUT); // 設定LED接腳為輸出

  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);
  // digitalWrite(trigPin, LOW);

  pinMode(vac, OUTPUT);
  digitalWrite(vac, HIGH);

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
  // Serial.println(Distance);s
  stop();
  vacoff();

  if (Serial.available() > 0) {
    char command = Serial.read();
  

    switch (command) {
      case '1':
        digitalWrite(ledPin1, HIGH); // 打開第一個LED
        break;
      case '2':
        digitalWrite(ledPin1, LOW); // 關閉第一個LED
        break;
      case '3':
        digitalWrite(ledPin2, HIGH); // 打開第二個LED
        break;
      case '4':
        digitalWrite(ledPin2, LOW); // 關閉第二個LED
        break;
      case 'F':
        forward(); // 向前运动
        break;
      case 'B':
        backward(); // 向后运动
        break;
      case 'L':
        left(); // 向左运动
        break;
      case 'R':
        right(); // 向右运动
        break;
      case 'S':
        stop(); // 停止运动
        break;
      case 'V':
        vacon();
        break;
      case 'N':
        vacoff(); // 停止运动
        break;
      case 'T':
        digitalWrite(vac, LOW);
        forward();
        delay(300);
        right();
        delay(300);
        break;
    }
    Serial.flush();
  }

}

void forward(void) {

  analogWrite(enA, 125);
	analogWrite(enB, 125);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

  delay(100);

}

void backward(void) {

  analogWrite(enA, 125);
	analogWrite(enB, 125);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

  delay(100);
}

void left(void) {
  
  analogWrite(enA, 125);
	analogWrite(enB, 125);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

  delay(100);
}

void right(void) {

  analogWrite(enA, 125);
	analogWrite(enB, 125);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

  delay(100);
}

void stop() {
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  
}

void vacon() {

	digitalWrite(vac, LOW);

  delay(100);

}

void vacoff() {

	digitalWrite(vac, HIGH);

}



