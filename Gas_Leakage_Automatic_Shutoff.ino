#include <Servo.h>

// Pin configuration
#define GAS_SENSOR_PIN 2   // MQ-2 digital output (D0)
#define BUZZER_PIN 3      // Passive buzzer
#define SERVO_PIN 9       // Servo signal

Servo gasServo;

bool servoMoved = false;
unsigned long startTime;

void setup() {
  pinMode(GAS_SENSOR_PIN, INPUT);

  gasServo.attach(SERVO_PIN);
  gasServo.write(0);  // Initial servo position

  Serial.begin(9600);

  // Allow the MQ-2 sensor to stabilize after power-up.
  startTime = millis();
  Serial.println("System initializing... waiting for sensor to stabilize.");
}

void loop() {
  // Wait 5 seconds after power-up for sensor stabilization.
  if (millis() - startTime < 5000) {
    return;
  }

  int gasState = digitalRead(GAS_SENSOR_PIN);
  Serial.print("Gas sensor state: ");
  Serial.println(gasState);

  // MQ-2 D0 is LOW when gas is detected.
  if (gasState == LOW && !servoMoved) {
    tone(BUZZER_PIN, 1000);  // 1 kHz warning tone

    gasServo.write(90);      // Move servo to shut the regulator
    servoMoved = true;

    Serial.println("WARNING: Gas detected! Buzzer ON, servo moved to 90 degrees.");
  }
  else if (gasState == HIGH) {
    noTone(BUZZER_PIN);
    Serial.println("Status: No gas detected. Buzzer OFF.");
  }

  delay(100);
}