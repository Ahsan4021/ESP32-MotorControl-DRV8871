// Updated ESP32-S3 GPIOs for 5 motors
#define IN1_M1 1   // PWM
#define IN2_M1 2   // DIR

#define IN1_M2 6   // PWM
#define IN2_M2 7   // DIR

#define IN1_M3 20  // PWM
#define IN2_M3 21  // DIR

#define IN1_M4 17  // PWM
#define IN2_M4 18  // DIR

#define IN1_M5 9   // PWM
#define IN2_M5 10  // DIR

// LEDC PWM channels
#define CH_M1 0
#define CH_M2 1
#define CH_M3 2
#define CH_M4 3
#define CH_M5 4

#define PWM_FREQ 20000      // 20kHz for DRV8871
#define PWM_RESOLUTION 8    // 8-bit resolution (0–255)

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32-S3 5-Motor PWM Control Starting...");

  // Set direction pins as OUTPUT
  pinMode(IN2_M1, OUTPUT); pinMode(IN2_M2, OUTPUT);
  pinMode(IN2_M3, OUTPUT); pinMode(IN2_M4, OUTPUT);
  pinMode(IN2_M5, OUTPUT);

  // Configure LEDC channels and attach to IN1 (PWM) pins
  ledcSetup(CH_M1, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(IN1_M1, CH_M1);

  ledcSetup(CH_M2, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(IN1_M2, CH_M2);

  ledcSetup(CH_M3, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(IN1_M3, CH_M3);

  ledcSetup(CH_M4, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(IN1_M4, CH_M4);

  ledcSetup(CH_M5, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(IN1_M5, CH_M5);
}

void loop() {
  // Run forward at different speeds
  Serial.println("Motors running FORWARD at various speeds...");
  // setMotor(IN2_M1, CH_M1, HIGH, 20);   // ~30%
  // setMotor(IN2_M2, CH_M2, HIGH, 80);  // ~50%
  // setMotor(IN2_M3, CH_M3, HIGH, 140);  // ~70%
  setMotor(IN2_M4, CH_M4, HIGH, 0);  // ~85%
  setMotor(IN2_M5, CH_M5, HIGH, 200);  // full speed

  // delay(5000);

  // // Run all motors in reverse at 50%
  // Serial.println("Motors running BACKWARD at 50%...");
  // setMotor(IN2_M1, CH_M1, LOW, 128);
  // setMotor(IN2_M2, CH_M2, LOW, 128);
  // setMotor(IN2_M3, CH_M3, LOW, 128);
  // setMotor(IN2_M4, CH_M4, LOW, 128);
  // setMotor(IN2_M5, CH_M5, LOW, 128);

  // delay(5000);
}

// Control individual motor
void setMotor(int dirPin, int pwmChannel, bool direction, int speed) {
  digitalWrite(dirPin, direction);
  ledcWrite(pwmChannel, speed); // Speed: 0–255 (8-bit)
}