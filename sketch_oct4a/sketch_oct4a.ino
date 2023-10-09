  // Controls power to right motor#define LEFT_MOTOR_OUT 2Y 
#define RIGHT_MOTOR_OUT A2
#define LEFT_MOTOR_OUT A1
#define JOYSTICK_Y A5
#define JOYSTICK_X A4
#define LED 13
// #define DEADZONE 150
#define MIDDLE 400

int x;
int y;
int Middle_X;
int Middle_Y;
int Middle;
//init the car
void setup() {
  pinMode(JOYSTICK_X, INPUT);
  pinMode(JOYSTICK_Y, INPUT);

  pinMode(LED, OUTPUT);
  pinMode(RIGHT_MOTOR_OUT, OUTPUT);    
  pinMode(LEFT_MOTOR_OUT, OUTPUT); 

  analogWrite(LEFT_MOTOR_OUT, 0);
  analogWrite(RIGHT_MOTOR_OUT, 0);

  Serial.begin(9600);

  Middle_X = analogRead(JOYSTICK_X);
  Middle_Y = analogRead(JOYSTICK_Y);
  Middle = ((Middle_X + Middle_Y)/ 2);

  Serial.println("Middle set to:");
  Serial.println(Middle);
  
}

//main loop
void loop() {

  // read joystick input values 0-1023
  x = analogRead(JOYSTICK_X);
  y = analogRead(JOYSTICK_Y);

  Serial.println("Y value:");
  Serial.println(analogRead(JOYSTICK_Y));
  Serial.println("X value:");
  Serial.println(analogRead(JOYSTICK_X));

  

  // Serial.println(x);
  // Serial.println(y);
 
  if (y > Middle) {
    digitalWrite(LED, HIGH);
    analogWrite(LEFT_MOTOR_OUT, 1023);
    analogWrite(RIGHT_MOTOR_OUT, 1023);
  } else if (y < Middle) {
    digitalWrite(LED, LOW);
    analogWrite(LEFT_MOTOR_OUT, 0);
    analogWrite(RIGHT_MOTOR_OUT, 0);
  } else {
    // Serial.println("NO INPUT READ");
    // Serial.println("Y value:");
    // Serial.println(analogRead(JOYSTICK_Y));
    // Serial.println("X value:");
    // Serial.println(analogRead(JOYSTICK_X));
  }


  // if (y > MIDDLE + DEADZONE) {
  //   if (x > MIDDLE + DEADZONE) {
  //     Serial.println("Turn Right");
  //     analogWrite(RIGHT_MOTOR_OUT, 0);
  //     analogWrite(LEFT_MOTOR_OUT, 1023);
  //   } else  if (x < MIDDLE - DEADZONE) {
  //     Serial.println("Turn Left");
  //     analogWrite(RIGHT_MOTOR_OUT, 1023);
  //     analogWrite(LEFT_MOTOR_OUT, 0);
  //   } else {
  //     Serial.println("Forwards");
  //     analogWrite(RIGHT_MOTOR_OUT, 1023);
  //     analogWrite(LEFT_MOTOR_OUT, 1023);
  //   }
  // } else if (y < MIDDLE - DEADZONE) {
  //   if (x > MIDDLE + DEADZONE) {
  //     Serial.println("Turn Right");
  //     analogWrite(RIGHT_MOTOR_OUT, 0);
  //     analogWrite(LEFT_MOTOR_OUT, 1023);
  //   } else  if (x < MIDDLE - DEADZONE) {
  //     Serial.println("Turn Left");
  //     analogWrite(RIGHT_MOTOR_OUT, 1023);
  //     analogWrite(LEFT_MOTOR_OUT, 0);
  //   } else {
  //     Serial.println("Backwards");
  //     analogWrite(RIGHT_MOTOR_OUT, 0);
  //     analogWrite(LEFT_MOTOR_OUT, 0);
  //   }
  // } else {
  //   analogWrite(RIGHT_MOTOR_OUT, 0);
  //     analogWrite(LEFT_MOTOR_OUT, 0);
  // }
}



