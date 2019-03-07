/* 
 * Description:
 * 
 * 
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - One or two hobby servo motors
 *  - Ultrasonic sensor
 *  
 *  Libraries
 *  ---------
 *  - Servo (comes with the Arduino IDE)
 *
 * Connections
 * -----------
 *  
 * 
 * Servo motor 1 --> Arduino Uno
 *  -----------------------------
 *    Red wire   |      5V
 *   Brown wire  |      GND
 *  Yellow wire  |      9
 *  
 *  Servo motor 2 --> Arduino Uno
 *  -----------------------------
 *    Red wire   |      5V
 *   Brown wire  |      GND
 *  Yellow wire  |      10
 *     
 * 
 * 
 *  Ultrasonic  ---> Arduino Uno
 *  -----------------------------
 *      VCC      |      5V
 *      GND      |      GND
 *      Echo     |      12
 *      Trig     |      13
 *     
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
 * 
 */

#include <Servo.h>  //include the servo motor library
#define trigPin 13  //trigger pin on ultrasonic sensor
#define echoPin 12  //echo pin on ultrasonic sensor

Servo myservo1, myservo2;  // create 2 servo objects
 
int pos_index = 0;    
int const total_positions = 10;
int servo_positions[total_positions] = 
    {156, 79, 88, 152, 34, 144, 28, 174, 117, 27};  //a random list of 10 servo positions
 
void setup() { 
  
  myservo1.attach(9);   // attaches the servo on pin 9 to the servo motor 1 
  myservo2.attach(10);  // attaches the servo on pin 10 to the servo motor 2 
  Serial.begin (9600);   
  pinMode(trigPin, OUTPUT); //set the trigPin as Output
  pinMode(echoPin, INPUT);  //set the echoPin as Input
} 
 
void loop() { 
  //Code that lets me test that the motors are functioning 
  for (pos_index = 0; pos_index <= total_positions; pos_index += 1) { 
    // in steps of 1 degree
    myservo1.write(servo_positions[pos_index]);    // tell servo 1 to go to new position
    delay(100);                                    // Insert small delay to give servo 1 a head start
    myservo2.write(servo_positions[pos_index]);    // tell servo 2 to go to new position
    delay(400);                                    // wait for servo 2 to reach the position
  }





  
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
    Serial.println(" cm");
  }
  delay(250);

} 
