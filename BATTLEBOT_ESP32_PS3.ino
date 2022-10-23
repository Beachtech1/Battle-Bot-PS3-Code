/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%BEACHTECH-ROBOTICS 
%Ps3 BattleBot Code for the ESP-Wroom-32 Dev broad
%Greggory Hartsfield
%July/28/2022
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <Ps3Controller.h>
#include <ESP32Servo.h>
#include <Math.h>

Servo motor_1;
Servo motor_2;
Servo motorWeapon_1;

const int buzzer = 32;                                  // Speaker to ESP Pin 32
int motorPin_1 = 27;                                    // ESC S1 to ESP Pin 14
int motorPin_2 = 14;                                    // ESC S2 to ESP Pin 27
int motorWeaponPin_1 = 26;                              // ESC to ESP Pin 26

int motorValue_1;
int motorValue_2;
int motorWeaponValue_1;

int ADC_Max = 4096;

int forwordModifier 1;                                  
int ternModifier 1;

void setup() {
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  
  Serial.begin(115200);
  Ps3.begin("00:00:00:00:00:00");                       //This is the Unique blueTooth MAC Adress for the Ps3 Controller 
  Serial.println("Ready.");

  pinMode(buzzer, OUTPUT);
  motor_1.setPeriodHertz(50);
  motor_1.attach(motorPin_1, 1000, 2000);
  motor_1.write(1500);                                  //Initializing ESC S1
  delay(1000);

  motor_2.setPeriodHertz(50);
  motor_2.attach(motorPin_2, 1000, 2000);
  motor_2.write(1500);                                  //Initializing ESC S2
  delay(1000);
  
  motorWeapon_1.setPeriodHertz(50);
  motorWeapon_1.attach(motorWeaponPin_1, 1000, 2000);
  motorWeapon_1.write(1000);                            //Initializing ESC Wepon
  delay(1000);
  

  
  Serial.print("Initializing Motors");
  tone(buzzer, 1000);
    delay(100);
  Serial.print(" . ");
  noTone(buzzer);
    delay(1000);
  Serial.print(" . ");
  tone(buzzer, 100);
    delay(1000);
  Serial.print(" . ");
  noTone(buzzer);
    delay(1000);
  Serial.println("Compleate");
  tone(buzzer, 100);
}

void loop() {
                                                        // Outputs from the controller
  if (Ps3.isConnected()) {

    // INPUT MIXING
    double x = Ps3.data.analog.stick.lx;
    double y = Ps3.data.analog.stick.ly;

    double r = sqrt(sq(y) + sq(x));               
    double t = atan(x/y);

    t = t + (0.785);                                    //  0.785398 = pi/4 

    float R = r * cos(t);
    float L = r * sin(t);
    
    int i = 1;
    if (y<0) {
      i= -1;
      }else {
      i= 1;
    }

    motorValue_1 = round(R * sqrt(2) * i);
    motorValue_2 = round(L * sqrt(2) * i);
    
    // Sending Data to the ESC S1
    motorValue_1 = map(motorValue_1, -256, 256, 1000, 2000);
    motor_1.write(motorValue_1);
    Serial.printf("%d ,", motorValue_1);
    
    // Sending Data to the ESC S2
    motorValue_2 = map(motorValue_2, -256, 256, 1000, 2000);
    motor_2.write(motorValue_2);
    Serial.printf("d\n", motorValue_2);
    
    // Sending Data to the ESC Weapon Motor 
    motorWeaponValue_1 =Ps3.data.analog.button.r2;
    motorWeaponValue_1 = map(motorWeaponValue_1, 0, 256, 1000, 2000);
    motorWeapon_1.write(motorWeaponValue_1);
    Serial.printf("%d\n", Ps3.data.analog.button.r2);

  }else{
    
  tone(buzzer, 1000);
  delay(100);
  noTone(buzzer);
  delay(1500);
  Serial.println("Diconected");
  }
}
