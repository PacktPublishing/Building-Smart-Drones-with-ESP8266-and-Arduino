void test_gyr_acc() {
  error = MPU6050_read (MPU6050_WHO_AM_I, &c, 1);
  if (error != 0) {
    while (true) {
      digitalWrite(13, HIGH);
      delay(300);
      digitalWrite(13, LOW);
      delay(300);
    }
  }
}
