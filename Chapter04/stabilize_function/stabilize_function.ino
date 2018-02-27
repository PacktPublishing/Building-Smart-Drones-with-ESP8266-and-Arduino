void stabilize() {



  P_x = (x_a + rad_tilt_LR) * 2.4;
  P_y = (y_a + rad_tilt_TB) * 2.4;
  I_x = I_x + (x_a + rad_tilt_LR) * dt_ * 3.7;
  I_y = I_y + (y_a + rad_tilt_TB) * dt_ * 3.7;
  D_x = x_vel * 0.7;
  D_y = y_vel * 0.7;
  //2.4 3.7 0.7
  //YAW

  P_z = (z_ang + wanted_z_ang) * 2.0;
  I_z = I_z + (z_ang + wanted_z_ang) * dt_ * 0.8;
  D_z = z_vel * 0.3;




  if (P_z > 160) {
    P_z = 160;
  }
  if (P_z < -160) {
    P_z = -160;
  }

  if (I_x > 30) {
    I_x = 30;
  }
  if (I_x < -30) {
    I_x = -30;
  }
  if (I_y > 30) {
    I_y = 30;
  }
  if (I_y < -30) {
    I_y = -30;
  }
  if (I_z > 30) {
    I_z = 30;
  }
  if (I_z < -30) {
    I_z = -30;
  }



  x_adder = P_x + I_x + D_x;
  y_adder = P_y + I_y + D_y;
}

