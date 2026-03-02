# ADXL345-Accelerometer-Based-Direction-Detection-on-MAX7219-LED-Matrix
This Arduino project reads motion data from the ADXL345 accelerometer  sensor using I2C communication and displays the movement direction  (RIGHT, LEFT, UP, DOWN, CENTER) on a 4-in-1 MAX7219 LED Matrix display.

The accelerometer measures X, Y, and Z axis acceleration. Based on 
threshold conditions (±0.5g), the program determines the tilt direction 
and scrolls the corresponding message on the LED matrix using the 
MD_Parola library.

Components Required:
- Arduino UNO
- ADXL345 Accelerometer Module
- MAX7219 4-Module (32x8) LED Matrix
- Breadboard
- Jumper wires

Connections:

ADXL345 Connections:
VCC  -> 3.3V (Recommended)
GND  -> GND
SDA  -> A4 (Arduino UNO)
SCL  -> A5 (Arduino UNO)

MAX7219 LED Matrix Connections:
VCC  -> 5V
GND  -> GND
DIN  -> D11
CLK  -> D13
CS   -> D10

Working:

1. The ADXL345 sensor communicates using I2C protocol at address 0x53.
2. In setup(), the sensor is activated by writing 0x08 to register 0x2D.
3. In loop(), 6 bytes of acceleration data are read starting from register 0x32.
4. Raw values are combined into 16-bit signed integers for X, Y, and Z axes.
5. The raw values are converted into acceleration in g using scale factor 0.0039.
6. If Ax > 0.5 → display "RIGHT"
7. If Ax < -0.5 → display "LEFT"
8. If Ay > 0.5 → display "UP"
9. If Ay < -0.5 → display "DOWN"
10. If none of the above → display "CENTER"
11. The message scrolls using MD_Parola animation functions.
12. The display updates continuously every 300 milliseconds.

Concepts Used:
- I2C Communication (Wire library)
- ADXL345 Accelerometer Interface
- MAX7219 LED Matrix Control
- MD_Parola Text Animation
- Bitwise operations for data combination
- Threshold-based direction detection
- Real-time motion sensing
