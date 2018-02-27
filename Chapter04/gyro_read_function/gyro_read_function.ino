void read_acc_gyr() {
  error = MPU6050_read (MPU6050_ACCEL_XOUT_H, (uint8_t *) &accel_t_gyro, sizeof(accel_t_gyro));

  uint8_t swap;
#define SWAP(x,y) swap = x; x = y; y = swap

  SWAP (accel_t_gyro.reg.x_accel_h, accel_t_gyro.reg.x_accel_l);
  SWAP (accel_t_gyro.reg.y_accel_h, accel_t_gyro.reg.y_accel_l);
  SWAP (accel_t_gyro.reg.z_accel_h, accel_t_gyro.reg.z_accel_l);
  SWAP (accel_t_gyro.reg.t_h, accel_t_gyro.reg.t_l);
  SWAP (accel_t_gyro.reg.x_gyro_h, accel_t_gyro.reg.x_gyro_l);
  SWAP (accel_t_gyro.reg.y_gyro_h, accel_t_gyro.reg.y_gyro_l);
  SWAP (accel_t_gyro.reg.z_gyro_h, accel_t_gyro.reg.z_gyro_l);

  gyroX_raw = accel_t_gyro.value.x_gyro;
  gyroY_raw = accel_t_gyro.value.y_gyro;
  gyroZ_raw = accel_t_gyro.value.z_gyro;
  double ang_x_raw = accel_t_gyro.value.y_accel;
  double ang_y_raw = accel_t_gyro.value.x_accel;
  double ang_z_raw = accel_t_gyro.value.z_accel;
  double ang_x_raw_sq = sq(ang_x_raw);
  double ang_y_raw_sq = sq(ang_y_raw);
  double ang_z_raw_sq = sq(ang_z_raw);
  accYangle_raw = (atan2(ang_y_raw, sqrt(ang_x_raw_sq + ang_z_raw_sq)) + PI) * RAD_TO_DEG - 180;
  accXangle_raw = (atan2(ang_x_raw, sqrt(ang_z_raw_sq + ang_y_raw_sq)) + PI) * RAD_TO_DEG - 180;

  x_ang = -accXangle_raw - ang_x_offset;
  y_ang = accYangle_raw - ang_y_offset;
  x_vel = (-gyroX_raw - gyr_x_raw_offset) / 65.5;
  y_vel = (-gyroY_raw - gyr_y_raw_offset) / 65.5;
  z_vel = (-gyroZ_raw - gyr_z_raw_offset) / 65.5;


  //komplementary filter
  dt_ = ((double)(micros() - timer) / 1000000);
  //if(dt_ > 0.1){
  // dt_ = 0.003;
  //}
  x_a = 0.99 * (x_a + x_vel * dt_) + 0.01 * x_ang;
  y_a = 0.99 * (y_a + y_vel * dt_) + 0.01 * y_ang;
  z_ang = z_ang + z_vel * dt_;
  timer = micros();
}
