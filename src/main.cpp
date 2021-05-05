// This example reads the raw values from the LSM6DS33
// accelerometer and gyro and prints those raw values to the
// serial monitor.
//
// The accelerometer readings can be converted to units of g
// using the conversion factors specified in the "Mechanical
// characteristics" table in the LSM6DS33 datasheet. We default to a
// full scale (FS) setting of +/- 16 g.
//
// The gyro readings can be converted to degrees per second (dps)
// using the "Mechanical characteristics" table in the LSM6DS33
// datasheet. We default to a full scale (FS) of +/- 1000 dps.
//

#include <Romi32U4.h>
#include "tap_detector.h"

TapDetector tapper;

void setup()
{
  //while(!Serial) {}

  Wire.begin();
  tapper.Init();
}

void loop()
{
  tapper.CheckTap();  
}