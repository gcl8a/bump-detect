#include "tap_detector.h"

void TapDetector::Init(void)
{ 
  Wire.begin();

  if (!imu.init())
  {
    // Failed to detect the LSM6.
    ledRed(1);
    while(1)
    {
      Serial.println(F("Failed to detect the LSM6."));
      delay(100);
    }
  }

  imu.enableDefault();

  imu.setFullScaleGyro(LSM6::GYRO_FS1000);
  imu.setGyroDataOutputRate(LSM6::ODR104);

  imu.setFullScaleAcc(LSM6::ACC_FS4);
  imu.setAccDataOutputRate(LSM6::ODR104);

  imu.writeReg(0x59, 0x04); 
  imu.writeReg(0x58, 0x0C); 
}

bool TapDetector::CheckTap(void)
{
  bool retVal = false;
  
  uint8_t tapReg = imu.readReg(0x1c);
  if(tapReg & 0x06)
  {
    Serial.print("tapped: ");
    Serial.println(tapReg, HEX);
  }
}
