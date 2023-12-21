#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED顯示寬度，以像素為單位
#define SCREEN_HEIGHT 64 // OLED顯示高度，以像素為單位
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "eyes.h" // 確保你的eye0圖案在這個檔案中

void setup() {
  Serial.begin(115200);                                 
  Serial.println("Booting");

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // 地址0x3D用於128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // 初始化失敗時不繼續執行
  }

  display.display(); // 顯示初始內容
  display.clearDisplay(); // 清除顯示
}

void loop() {
  display.clearDisplay(); // 清除顯示緩衝區
  display.drawBitmap(16, 8, eye0, 32, 32, WHITE); // 在指定位置顯示eye0圖案
  display.drawBitmap(80, 8, eye0, 32, 32, WHITE); // 在另一側顯示eye0圖案
  display.display(); // 更新OLED顯示
  delay(1000); // 等待一秒
}
