#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "eyes.h"

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

void setup() {
  Serial.begin(9600);
   
  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);
  // digitalWrite(trigPin, LOW);

  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, HIGH);


  pinMode(vac, OUTPUT);
  //digitalWrite(vac, LOW);
  
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
        forward(500);
        break;
      case 'B':
        display.clearDisplay();
        display.drawBitmap(16, 8, eye2, 32, 32, WHITE);
        display.drawBitmap(80, 8, eye2, 32, 32, WHITE);
        display.display();
        backward();
        break;
      case 'L':
        display.clearDisplay();
        display.drawBitmap(36, 8, eye9, 32, 32, WHITE);
        display.drawBitmap(100, 8, eye9, 32, 32, WHITE);
        display.display();
        left();
        break;
      case 'R':
        display.clearDisplay();
        display.drawBitmap(-4, 8, eye9, 32, 32, WHITE);
        display.drawBitmap(60, 8, eye9, 32, 32, WHITE);
        display.display();
        right();
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
        // digitalWrite(vac, HIGH);
        // forward(100);
        // delay(200);
        // right();
        // delay(200);
        // break;
        display.clearDisplay();
        display.drawBitmap(16, 8, eye1, 32, 32, WHITE);
        display.drawBitmap(80, 8, eye1, 32, 32, WHITE);
        display.display();
        forward(200);
    }
    Serial.flush();
  }

}

void forward(int Ftime) {

  analogWrite(enA, 200);
	analogWrite(enB, 160);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in4, LOW);
	digitalWrite(in3, HIGH);

  delay(Ftime);

}


void backward(void) {

  analogWrite(enA, 200);
	analogWrite(enB, 120);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);

  delay(300);
}

void left(void) {
  
  analogWrite(enA, 75);
	analogWrite(enB, 75);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in4, LOW);
	digitalWrite(in3, HIGH);

  delay(300);
}

void right(void) {

  analogWrite(enA, 75);
	analogWrite(enB, 75);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);

  delay(300);
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