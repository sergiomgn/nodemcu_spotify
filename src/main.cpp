#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFiClient.h>
#include <ESP8266WiFi.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define SSID "Vodafone-D64A17"
#define PASSWORD "FG5DQ8N53z"

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  WiFi.begin(SSID, PASSWORD);

  display.print("Connecting: ");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    display.print(".");
  }

  delay(2000);
  display.clearDisplay();
  // Display static text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println(WiFi.localIP());
  display.display();
}

void loop() {
  
}