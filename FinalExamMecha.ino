#include <OneWire.h>
#include <DallasTemperature.h>
#include <U8g2lib.h>

// SDA, SCL for each display
U8G2_SSD1306_128X64_NONAME_F_SW_I2C display1(U8G2_R0, 4, 3, U8X8_PIN_NONE);   // SCL, SDA
U8G2_SSD1306_128X64_NONAME_F_SW_I2C display2(U8G2_R0, 6, 5, U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C display3(U8G2_R0, 8, 7, U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C display4(U8G2_R0, 10, 9, U8X8_PIN_NONE);

// Sensor and data variables
int tempsensor = 2, cat = 0, cat1 = 0, TDS = 0, TDSsum = 0, TDSshown = 0;
float tempC = 0, tempF = 0, v = 0, pH = 0, tempadjust = 0, tdsvoltage = 0, pHsum = 0, averagepH = 0, averagetemp = 0, tempsum = 0;
OneWire oneWire(tempsensor);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);

  display1.begin();
  display2.begin();
  display3.begin();
  display4.begin();

  sensors.begin();
}

void loop() {
  temperatureSensor();
  temperatureSensorScreen();
  pHSensor();
  pHSensorScreen();
  TDSSensor();
  TDSSensorScreen();
}

void temperatureSensor() {
  tempsum = 0;
  for (int i = 0; i < 8; i++) {
    sensors.requestTemperatures();
    tempC = sensors.getTempCByIndex(0);
    tempF = tempC * (9.0/5.0) + 32.0;
    Serial.println(tempF);
    Serial.println("temp");
    tempsum += tempF;
    delay(100);
  }
  averagetemp = tempsum / 8;
}

void temperatureSensorScreen() {
  display4.clearBuffer();
  display4.setFont(u8g2_font_fub20_tr);
  display4.setCursor(0, 40);
  display4.print(averagetemp);
  display4.print(" F");
  display4.sendBuffer();
}

void pHSensor() {
  pHsum = 0;
  for (int i = 0; i < 50; i++) {
    cat = analogRead(A5);
    v = cat * (5.0 / 1023.0);
    pH = (-5.75) * v + (21.408);
    Serial.println(pH);
 Serial.println("pH");
    pHsum += pH;
    delay(100);
  }
  averagepH = pHsum / 50;
}

void pHSensorScreen() {
  display3.clearBuffer();
  display3.setFont(u8g2_font_fub20_tr);
  display3.setCursor(0, 40);
  display3.print(averagepH, 2);
  display3.print(" pH");
  display3.sendBuffer();
}

void TDSSensor() {
  TDSsum = 0;
  for (int i = 0; i < 50; i++) {
    cat1 = analogRead(A0);
    v = cat1 * (5.0 / 1023.0);
    tempadjust = 1.0 + 0.2 * (tempC - 25.0);
    tdsvoltage = v / tempadjust;
    TDS = ((133.42 * pow(tdsvoltage, 3)) - (255.86 * pow(tdsvoltage, 2)) + (857.39 * tdsvoltage)) * 0.5;
    Serial.println(TDS);
  Serial.println("TDS");
    TDSsum += TDS;
    delay(100);
  }
  TDSshown = TDSsum / 50;
}

void TDSSensorScreen() {
  display1.clearBuffer();
  display1.setFont(u8g2_font_fub20_tr);
  display1.setCursor(0, 40);
  display1.print(TDSshown);
  display1.print(" TDS");
  display1.sendBuffer();
}
