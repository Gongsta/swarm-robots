%Initalizing the Arduino Nano
clear a;
a = arduino('COM5', 'Nano');

%Assigning the pins and turning the Motors on
motor1SpeedPin = 'D3';
motor1DirectionPin = 'D4';
motor2SpeedPin = 'D5';
motor2DirectionPin = 'D6';

%Initial settings
direction = 1;
initialPWMVoltage = 0.001;
writeDigitalPin(a,motor1DirectionPin,direction);
writeDigitalPin(a,motor2DirectionPin,direction);
writePWMVoltage(a,motor1SpeedPin,initialPWMVoltage);
writePWMVoltage(a,motor2SpeedPin,initialPWMVoltage);

% wait for the change to take effect on the hardware
 


