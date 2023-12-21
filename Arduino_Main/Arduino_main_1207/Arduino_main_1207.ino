#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "eyes.h"
void forward(int Ftime, bool closeStop=true, bool slowMode=false);
void backward(int Btime, bool slowMode=false);

int vac = 7;

// Motor A connections
int enA = 3;
int in1 = 6;
int in2 = 5;
// Motor B connections
int enB = 9;
int in3 = 11;
int in4 = 10;               

int redLED = 12;

int const ultra5V = 4;
int const trigPin = 2;
int const echoPin = 13;
int Duration;
int Distance;

void setup() {
  Serial.begin(9600);
   
  pinMode(ultra5V, OUTPUT);
  digitalWrite(ultra5V, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);

  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, HIGH);


  pinMode(vac, OUTPUT);
  // pinMode(vac, INPUT);
  
  vacoff();

  // vacon();
  

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

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.display();
  display.clearDisplay();

}

void loop() {

  stop();
  display.clearDisplay();
  display.drawBitmap(16, 8, eye0, 32, 32, WHITE);
  display.drawBitmap(80, 8, eye0, 32, 32, WHITE);
  display.display();
  // vacoff();

  if (Serial.available() > 0) {
    char command = Serial.read();
  

    switch (command) {
      case 'A':
        digitalWrite(redLED, LOW);
        display.clearDisplay();
        display.drawBitmap(16, 8, eye13i, 32, 32, WHITE);
        display.drawBitmap(80, 8, eye13d, 32, 32, WHITE);
        display.display();
        delay(2000);
      
        digitalWrite(redLED, HIGH);
        display.clearDisplay();
        display.drawBitmap(16, 8, eye13d, 32, 32, WHITE);
        display.drawBitmap(80, 8, eye13i, 32, 32, WHITE);
        display.display();
        delay(300);
        break;
      case 'F':
        display.clearDisplay();
        display.drawBitmap(16, 8, eye1, 32, 32, WHITE);
        display.drawBitmap(80, 8, eye1, 32, 32, WHITE);
        display.display();
        forward(500, true);
        break;
      case 'B':
        display.clearDisplay();
        display.drawBitmap(16, 8, eye2, 32, 32, WHITE);
        display.drawBitmap(80, 8, eye2, 32, 32, WHITE);
        display.display();
        backward(300);
        break;
      case 'L':
        display.clearDisplay();
        display.drawBitmap(36, 8, eye9, 32, 32, WHITE);
        display.drawBitmap(100, 8, eye9, 32, 32, WHITE);
        display.display();
        left(65); // 65
        break;
      case 'R':
        display.clearDisplay();
        display.drawBitmap(-4, 8, eye9, 32, 32, WHITE);
        display.drawBitmap(60, 8, eye9, 32, 32, WHITE);
        display.display();
        right(65);
        break;
      case 'S':
        display.clearDisplay();
        display.drawBitmap(16, 8, eye8, 32, 32, WHITE);
        display.drawBitmap(80, 8, eye8, 32, 32, WHITE);
        display.display();
        stop();
        break; 
      case 'V':
        display.clearDisplay();
        display.drawBitmap(16, 8, eye8, 32, 32, WHITE);
        display.drawBitmap(80, 8, eye8, 32, 32, WHITE);
        display.display();
        vacon();
        break;
      case 'N':
        vacoff();
        break;
      case 'T':
        digitalWrite(vac, HIGH);
        whirl(5700);
        digitalWrite(vac, LOW);
        // storm();
        display.clearDisplay();
        display.drawBitmap(16, 8, eye1, 32, 32, WHITE);
        display.drawBitmap(80, 8, eye1, 32, 32, WHITE);
        display.display();
        break;
    }
    Serial.flush();
  }

}

void forward(int Ftime, bool closeStop=true, bool slowMode=false) {

  if(!slowMode){
    analogWrite(enA, 220);
    analogWrite(enB, 160);
  }else{
    analogWrite(enA, 150);
    analogWrite(enB, 120);
  }

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in4, LOW);
	digitalWrite(in3, HIGH);

  if(closeStop){
    for(int i=0;i<10;i++){
      assertDistance();
      delay(Ftime/10);
    }
  }

}


void backward(int Btime, bool slowMode=false) {

  if(!slowMode){
    analogWrite(enA, 200);
    analogWrite(enB, 120);
  }else{
    analogWrite(enA, 150);
    analogWrite(enB, 120);
  }

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);

  delay(Btime);
}

void left(int Ltime) {
  
  analogWrite(enA, 200);
	analogWrite(enB, 120);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in4, LOW);
	digitalWrite(in3, HIGH);

  delay(Ltime);
}

void right(int Rtime) {

  analogWrite(enA, 200);
	analogWrite(enB, 120);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);

  delay(Rtime);
}

void stop() {
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in4, LOW);
	digitalWrite(in3, LOW);
  
}

void vacon() {

	digitalWrite(vac, HIGH);

  delay(100);

}

void vacoff() {

	digitalWrite(vac, LOW);

}

void assertDistance(){
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH);
  Distance = Duration * 0.034 / 2; // unit: cm
  // Serial.println(Distance);
  if(Distance<22){
    stop();
  }
}

void adjustDistance(int d){
  while(true){
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    Duration = pulseIn(echoPin, HIGH);
    Distance = Duration * 0.034 / 2; // unit: cm
    if((Distance-d)<3 && (Distance-d)>-3){
      stop();
      break;
    }
    if((Distance-d)>3){
      forward(200, false, true);
    }
    if((Distance-d)<-3){
      backward(200, true);
    }
  }
}

void storm(){


  adjustDistance(18);
  delay(1000);

  right(270);
  stop();
  delay(1000);

  adjustDistance(18);
  delay(1000);

  left(250);
  stop();
  delay(1000);
  
  digitalWrite(vac, HIGH);
  
  whirl(5700);

  digitalWrite(vac, LOW);
}

void whirl(int Wtime) {

  analogWrite(enA, 200);
	analogWrite(enB, 80);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);

  delay(Wtime);
}
