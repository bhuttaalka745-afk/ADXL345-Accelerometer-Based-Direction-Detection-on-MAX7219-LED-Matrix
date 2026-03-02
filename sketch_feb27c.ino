#include <Wire.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define ADXL345 0x53

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 10

MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

int16_t AccX, AccY, AccZ;
float Ax, Ay, Az;

void setup()
{
  Wire.begin();
  P.begin();
  P.setIntensity(5);
  P.displayClear();

  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);
  Wire.write(0x08);
  Wire.endTransmission();

 
  P.displayClear();
}

void loop()
{

  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true);

  AccX = Wire.read() | (Wire.read() << 8);
  AccY = Wire.read() | (Wire.read() << 8);
  AccZ = Wire.read() | (Wire.read() << 8);

  Ax = AccX * 0.0039;
  Ay = AccY * 0.0039;
  Az = AccZ * 0.0039;

  P.displayClear();

  if (Ax > 0.5)
  {
    P.displayText("RIGHT", PA_CENTER, 80, 0, PA_PRINT, PA_SCROLL_LEFT);
  }
  else if (Ax < -0.5)
  {
    P.displayText("LEFT", PA_CENTER, 80, 0, PA_PRINT, PA_SCROLL_LEFT);
  }
  else if (Ay > 0.5)
  {
    P.displayText("UP", PA_CENTER, 80, 0, PA_PRINT,PA_SCROLL_LEFT);
  }
  else if (Ay < -0.5)
  {
    P.displayText("DOWN", PA_CENTER, 80, 0, PA_PRINT, PA_SCROLL_LEFT);
  }
  else
  {
    P.displayText("CENTER", PA_CENTER, 100, 0, PA_PRINT, PA_SCROLL_LEFT);
  }

  while(!P.displayAnimate());
  P.displayReset();

  delay(300);
}