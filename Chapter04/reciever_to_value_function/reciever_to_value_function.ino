void reciever_to_value() {
  if (ESC > 900 && ESC < 2000) {
    main_power = map(ESC, 1080, 2000, 670, 2000);
  } else {
    main_power = 800;
  }

  yaw_temp = AILERON;

  if (AILERON > 900 && AILERON < 2000) {
    if (yaw_temp > 1550 || yaw_temp < 1450) {
      rad_rotate = map(yaw_temp, 970, 2000, 180, -180);
    } else {
      rad_rotate = 0;
    }
  }


  if (ppp > 900 && ppp < 2000) {
    rad_tilt_TB = map(ppp, 970, 2000, -44, 44);
  } else {
    rad_tilt_TB = 0;
  }


  if (ELEVATOR > 900 && ELEVATOR < 2000) {
    rad_tilt_LR = map(ELEVATOR, 1000, 2000, -44, 44);
  } else {
    rad_tilt_LR = 0;
  }

  PID_tune_2 = 0.1 * (map(ppp3, 1000, 2010, 4, 15));
  PID_tune = 0.1 * (map(ppp2, 1000, 2010, 15, 50));
  //     gimbal_wanted_ang = map(ppp2,1000,2010,100,0);


}
