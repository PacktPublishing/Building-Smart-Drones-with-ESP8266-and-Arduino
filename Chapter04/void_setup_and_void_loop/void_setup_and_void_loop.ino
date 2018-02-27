void setup()
{

  digitalWrite(13, HIGH);
  myservoT.attach(7);   //7-TOP
  myservoR.attach(8); //8-Right
  myservoB.attach(9); //9 - BACK
  myservoL.attach(10); //10 LEFT
  Wire.begin();
  PCintPort::attachInterrupt(ESC_IN, escRead, CHANGE);
  PCintPort::attachInterrupt(ELEVATOR_IN, elevatorRead, CHANGE);
  PCintPort::attachInterrupt(AILERON_IN, aileronRead, CHANGE);
  PCintPort::attachInterrupt(ppp_in, pppRead, CHANGE);
  PCintPort::attachInterrupt(ppp2_in, ppp2Read, CHANGE);
  PCintPort::attachInterrupt(ppp3_in, ppp3Read, CHANGE);
  test_gyr_acc();
  test_radio_reciev();

  mpu6050_init();
  // Clear the 'sleep' bit to start the sensor.
  MPU6050_write_reg (MPU6050_PWR_MGMT_1, 0);
  //  delay(1000);

  main_power = 0;
  motor_arm();
  delay(800);
  digitalWrite(13, LOW);

}


void loop()
{

  timer_counter++;
  if (timer_counter > 10000) {

    digitalWrite(13, HIGH);
    timer_counter = 0;
  }
  check_radio_signal();
  reciever_to_value();
  calc_wanted_z_ang();
  read_acc_gyr();
  if (main_power > 750) {
    stabilize();
  } else {
    zero_on_zero_throttle();
  }
  set_power();
}

