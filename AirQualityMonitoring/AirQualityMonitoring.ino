#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <SimpleDHT.h>

// Define DHT11 sensor pin
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

// Initialize LCD with auto I2C address detection
hd44780_I2Cexp lcd;

void setup() {
  Serial.begin(9600);
  Serial.println("TEMPERATURE AND HUMIDITY MONITORING");

  // Initialize LCD
  if (lcd.begin(16, 2)) {  // Automatically detects the I2C address
    Serial.println("LCD Initialization Failed!");
    while (1);
  }

  lcd.print("Hello, World!");

  // Set up air quality sensor pins
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  
  delay(2000); // Allow time for LCD to initialize
}

void loop() {
  lcd.clear();
  
  lcd.setCursor(2, 0);
  lcd.print("AIR QUALITY");
  lcd.setCursor(0, 1);
  lcd.print("MONITORING");
  
  delay(1000);
  
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err=");
    Serial.println(err);
    delay(1000);
    return;
  }

  int m = analogRead(A0);
  int n = analogRead(A1);
  int o = analogRead(A2);
  
  Serial.print("Air Quality: ");
  Serial.print(m); Serial.print(" ");
  Serial.print(n); Serial.print(" ");
  Serial.print(o); Serial.println();
  
  Serial.print("Temperature: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print("Humidity: ");
  Serial.print((int)humidity); Serial.println(" %H");

  // Display values on LCD
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("AQ: "); 
  lcd.print(m);
  
  lcd.setCursor(6, 0);
  lcd.print(n);
  
  lcd.setCursor(11, 0);
  lcd.print(o);

  lcd.setCursor(3, 1);
  lcd.print("Temp: ");
  lcd.print((int)temperature);
  lcd.print("C");

  lcd.setCursor(10, 1);
  lcd.print("Hum: ");
  lcd.print((int)humidity);
  lcd.print("%");
  
  delay(2000);
}
