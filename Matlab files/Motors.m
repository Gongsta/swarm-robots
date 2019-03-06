%Initalizing the Arduino Nano
clear a;
a = arduino('COM3','Uno');

%Sur le motor Shield:
% IN1 -----> PWM, D3
% IN2 -----> digital pin, D4
% IN3 -----> PWM, D5
% IN4 -----> digital pin, D6

%Assigning the pins and turning the Motors on
motor1SpeedPin = 'D3';
motor1DirectionPin = 'D4';
motor2SpeedPin = 'D5';
motor2DirectionPin = 'D6';

%Initial settings
while(true)
    direction = 1;
    initialPWMVoltage = 0.001;
    writeDigitalPin(a,motor1DirectionPin,direction);
    writeDigitalPin(a,motor2DirectionPin,direction);
    writePWMVoltage(a,motor1SpeedPin,initialPWMVoltage);
    writePWMVoltage(a,motor2SpeedPin,initialPWMVoltage);
    
    pause(0.5);
    
    direction = 0;
    initialPWMVoltage = 4;
    writeDigitalPin(a,motor1DirectionPin,direction);
    writeDigitalPin(a,motor2DirectionPin,direction);
    writePWMVoltage(a,motor1SpeedPin,initialPWMVoltage);
    writePWMVoltage(a,motor2SpeedPin,initialPWMVoltage);
    
    pause(0.5);

% wait for the change to take effect on the hardware
 

end
