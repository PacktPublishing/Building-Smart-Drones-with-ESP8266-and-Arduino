void mpu6050_init() {
  MPU6050_write_reg (MPU6050_GYRO_CONFIG, 0x08);  // 0x00 = 250 deg/s _______ 0x08 = 500deg/s (dela med 65.5 för deg/s) ____________  ___ 0x10 = 1000deg/s  ___  0xC = 2500 deg/s
  MPU6050_write_reg (MPU6050_ACCEL_CONFIG, 0x08); // 0x00 = +-2g  _____ 0x08 = +-4 g ___....
  MPU6050_write_reg (MPU6050_CONFIG, 0x03);    //LOW-pass filter

}
