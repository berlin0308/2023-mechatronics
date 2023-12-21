int ledPin1 = 7; // 第一個LED接腳
int ledPin2 = 13; // 第二個LED接腳

int const trigPin = 13;
int const echoPin = 12;
int Duration;
int Distance;

const int in1Pin = 4; // 连接到L298N的IN1引脚
const int in2Pin = 5; // 连接到L298N的IN2引脚
const int in3Pin = 6; // 连接到L298N的IN3引脚
const int in4Pin = 7; // 连接到L298N的IN4引脚

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT); // 設定LED接腳為輸出
  pinMode(ledPin2, OUTPUT); // 設定LED接腳為輸出

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);

  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, HIGH); // 發射超音波
  delay(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH); // 超音波發射到接收的時間
  Distance = Duration * 0.034 / 2; // 計算距離(cm)
  forward();

  // Serial.println(Distance);

  if (Serial.available() > 0) {
    char command = Serial.read();
    

    switch (command) {
      case '1':
        digitalWrite(ledPin1, HIGH); // 打開第一個LED
        delay(3000);
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
    }
  }
}

void forward() {
  analogWrite(in1Pin, 80);
  analogWrite(in2Pin, 0);
  analogWrite(in3Pin, 80);
  analogWrite(in4Pin, 0);
}

void backward() {
  analogWrite(in1Pin, 0);
  analogWrite(in2Pin, 80);
  analogWrite(in3Pin, 0);
  analogWrite(in4Pin, 80);
}

void left() {
  analogWrite(in1Pin, 80);
  analogWrite(in2Pin, 0);
  analogWrite(in3Pin, 0);
  analogWrite(in4Pin, 0);
}

void right() {
  analogWrite(in1Pin, 0);
  analogWrite(in2Pin, 0);
  analogWrite(in3Pin, 80);
  analogWrite(in4Pin, 0);
}

void stop() {
  analogWrite(in1Pin, 0);
  analogWrite(in2Pin, 0);
  analogWrite(in3Pin, 0);
  analogWrite(in4Pin, 0);
}
