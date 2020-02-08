/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//ADC_MODE(ADC_VCC);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN, LOW);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Hello, world!");
  display.display();

  display.setTextSize(1);
  display.setCursor(0, 25);
  display.println("Voltaje");
  display.display(); 

  delay(2000);
  display.clearDisplay();
}

void loop() {

  //float voltage = ESP.getVcc();//analogRead(A0);
  float voltage = analogRead(A0);
  voltage = map(voltage, 0, 1023, 0, 4.2);  //bateria_voltaje_actual = bateria_voltaje_actual/1024.0;

  //voltage = 4.20;
  //const int variable = 10;
  String test = String(voltage);
  String cabecera = "Voltaje = ";
  String msg = cabecera + test;

  display.setTextSize(1);
  display.setCursor(0, 40);
  //display.print("Voltaje = "); 
  display.print(msg);
  //display.setCursor(70,40); Serial.println(test);
  display.display(); 

  //display.setTextSize(1);
  //display.setCursor(0, 10);
  //display.print(test); 
  //display.display(); 

  delay(2000);
  display.clearDisplay();
  msg = "";
  
}
