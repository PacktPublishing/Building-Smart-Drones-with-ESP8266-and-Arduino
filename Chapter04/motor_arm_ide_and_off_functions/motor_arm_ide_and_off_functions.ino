

void motor_arm() {
  delay(2000);
  myservoT.writeMicroseconds(800); //for degees 0-180
  myservoR.writeMicroseconds(800); //for degees 0-180
  myservoB.writeMicroseconds(800); //for degees 0-180
  myservoL.writeMicroseconds(800); //for degees 0-180
  delay(4700);
}


void motor_idle() {
  myservoT.write(57); //for degees 0-180
  myservoR.write(57); //for degees 0-180
  myservoB.write(57); //for degees 0-180
  myservoL.write(57); //for degees 0-180
}


void motor_off() {
  main_power = 19;
  myservoT.write(19); //for degees 0-180
  myservoR.write(19); //for degees 0-180
  myservoB.write(19); //for degees 0-180
  myservoL.write(19); //for degees 0-180
}
