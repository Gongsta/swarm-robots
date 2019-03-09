/* 
 * Description:
 * 
 * A simple program that tests all of the functionalities in my robot.
 * 
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - 3 servo motors
 *  - Ultrasonic sensor
 *  - a L298N motor controller breakout
 *  - two small 5V DC motors
 *  - RGB light
 *  -
 *  
 *  Libraries
 *  ---------
 *  - Servo (comes with the Arduino IDE)
 *  - SPI
 *  - RF24
 *
 * Connections
 * -----------
 *  
 * 
 * Servo motor 1 --> Arduino Uno
 *  -----------------------------
 *    Red wire   |      5V
 *   Brown wire  |      GND
 *  Yellow wire  |      D6
 *  
 * Servo motor 2 --> Pixy2
 *  -----------------------------
 *  
 *  Servo motor 3 --> Pixy2
 *  -----------------------------
 * 
 *  Ultrasonic ---> Arduino Uno
 *  -----------------------------
 *      VCC      |      5V
 *      GND      |      GND
 *      Echo     |      D14
 *      Trig     |      D15
 *     
 *     L298N   ---> Arduino Uno
 *  -----------------------------
 *      GND      |      GND
 *      IN1      |      D5            IN1 requires PWM
 *      IN2      |      D4
 *      IN3      |      D3            IN3 requires PWM
 *      IN4      |      D2   
 *     
 *     L298N  --->   Motors
 *  -----------------------------
 *      OUT1     | DC Motor 1 wire 1
 *      OUT2     | DC Motor 1 wire 2
 *      OUT3     | DC Motor 2 wire 1
 *      OUT4     | DC Motor 2 wire 2
 *      
 *     L298N  --->   Power
 *  -----------------------------
 *      +12V     | 9V Power Supply
 *      GND      | GND Power supply    
 *      
 * RGB Light   --> Arduino Uno
 *  -----------------------------
 *    GND        |      GND
 *   Red light   |      D1
 *  Green light  |      D7
 *  Blue light   |      D8
 *     
 *     
 *     Pixy2   --> Arduino Uno
 *  -----------------------------
 *    
 *    
 *   nRF24   -->  Arduino Uno
 *  -----------------------------
 *      IRQ      |      -
 *      MOSI     |     D11
 *      CSN      |     D10
 *      VCC      |     3.3v (careful not 5v or else will burn)
 *      GND      |     GND
 *      CE       |     D9
 *      SCK      |     D13
 *      MISO     |     D12
 *  More information
 *  ----------------
 *  
 *  Servo Motor
 *  
 *  For more information on the servo library, see https://www.arduino.cc/en/reference/servo
 *  
 *  
 * Ultrasonic sensor
 * 
 * For information on the ultrasonic transducer: https://en.wikipedia.org/wiki/Ultrasonic_transducer
 * For information on ultrasounds: https://en.wikipedia.org/wiki/Ultrasound
 * HC-SR04 datasheet: https://docs.google.com/document/d/1Y-yZnNhMYy7rwhAgyL_pfa39RsB-x2qR4vP8saG73rE
 * Information about the pulseIn function: https://www.arduino.cc/en/Reference/PulseIn
 *  
 * L298N motor driver
 * L298N datasheet: http://www.ti.com/lit/ds/symlink/l293.pdf
 */

#include <Servo.h>  //include the servo motor library

#include <Pixy2.h>  //include the Pixy2 library

//nRF24 libraries
#include <SPI.h>
#include "RF24.h"

Servo myservo1; // create servo object 1
//Servo myservo2; //create servo object 2

Pixy2 pixy;   //create the Pixy object

int pos_index = 0;    
int const total_positions = 10;
int servo_positions[total_positions] = 
    {156, 79, 88, 152, 34, 144, 28, 174, 117, 27};  //a random list of 10 servo positions

 
#define trigPin 15  //trigger pin on ultrasonic sensor
#define echoPin 14  //echo pin on ultrasonic sensor

//Defining the RGB Pins
#define RED_PIN 1
#define GREEN_PIN 7
#define BLUE_PIN 8

char message = 'A';

int led_pin = 8;

RF24 radio(9,10);  //Radio Pins

// Radio pipe addresses for the 2 nodes to communicate.
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

int speed1     = 5; //Controls speed (PWM) for DC motor 1
int direction1 = 4; //Controls direction for DC motor 1
int speed2     = 3; //Controls speed (PWM) for DC motor 2
int direction2 = 2; //Controls direction for DC motor 2

bool direction = HIGH;  // Start the motor by moving it towards one direction. Whether it is
                        // clockwise or anticlockwise depends on how you have connected the 
                        // motor's coil. Setting it LOW will make it move in the other direction.




void setup() { 
  //Servo Motor setup
  myservo1.attach(6);   // attaches the servo on pin 9 to the servo motor 1 
//  myservo2.attach(10);  // attaches the servo on pin 10 to the servo motor 2 
  Serial.begin (9600);

  //Ultrasonic sensor setup  
  pinMode(trigPin, OUTPUT); //set the trigPin as Output
  pinMode(echoPin, INPUT);  //set the echoPin as Input

  //DC Motor setup
  pinMode(direction1, OUTPUT);  
  pinMode(speed1, OUTPUT);  
  pinMode(direction2, OUTPUT);  
  pinMode(speed2, OUTPUT);  

  //RGB Light setup
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  //Transmitter radio setup
  radio.begin();
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);  
  radio.printDetails();
} 
 
void loop() { 
  //Code that lets me test that the motors are functioning 
  for (pos_index = 0; pos_index <= total_positions; pos_index += 1) { 
    // in steps of 1 degree
    myservo1.write(servo_positions[pos_index]);    // tell servo 1 to go to new position
    delay(100);                                    // Insert small delay to give servo 1 a head start
//    myservo2.write(servo_positions[pos_index]);    // tell servo 2 to go to new position
//    delay(400);                                    // wait for servo 2 to reach the position
  }


  digitalWrite(direction1,direction);   // Direction control motor 1
  digitalWrite(direction2,direction);   // Direction control motor 2
  analogWrite(speed1, 150);             // PWM Speed Control motor 1
  analogWrite(speed2, 150);             // PWM Speed Control motor 2


  
  //Code that tests the RGB light
  digitalWrite(BLUE_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(RED_PIN, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000);                       // wait for a second

  
  //Code that allows me to measure distance from ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm"); //Prints the distance object is from robot
  }
  delay(250);

} 
