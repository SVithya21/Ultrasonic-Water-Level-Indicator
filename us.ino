#include <Wire.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// Buzzer (optional)
const int buzzerPin = 7;

// LCD object (I2C address 0x27, 16 columns x 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
float distance;
int levelPercent;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Water Level Monitor");
  delay(2000);
  lcd.clear();
}

void beepBuzzer() {
  digitalWrite(buzzerPin, HIGH);  // Turn buzzer ON
  delay(200);                     // Beep duration 200 ms
  digitalWrite(buzzerPin, LOW);   // Turn buzzer OFF
  delay(1000);                    // Wait 1 second after beep
}


void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse duration (timeout after 30ms)
  duration = pulseIn(echoPin, HIGH, 30000);

  // Handle sensor error
  if (duration == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    digitalWrite(buzzerPin, HIGH);
    delay(2000);
    digitalWrite(buzzerPin, LOW);
    return;
  }

  // Convert to distance in cm
  distance = duration * 0.0343 / 2;
  if (distance > 20) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Out of Range");
  digitalWrite(buzzerPin, LOW);  // Optional
  delay(1000);  // Optional
  return;
}

    Serial.print("Distance: ");
    Serial.print(distance, 2);
    Serial.println(" cm");

    levelPercent = map(distance, 0, 20, 100, 0);
    levelPercent = constrain(levelPercent, 0, 100);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lvl: ");
    lcd.print(distance, 1);
    lcd.print(" cm");

    lcd.setCursor(0, 1);
    lcd.print("Tank: ");
    lcd.print(levelPercent);
    lcd.print("%");

    if (distance <= 5) {
      lcd.setCursor(12, 1);
      lcd.print("FULL");
      beepBuzzer();
    } else if (distance >= 15) {
      lcd.setCursor(11, 1);
      lcd.print("EMPTY");
      beepBuzzer();
    } else {
      digitalWrite(buzzerPin, LOW);
    } 


  delay(1000);
}
