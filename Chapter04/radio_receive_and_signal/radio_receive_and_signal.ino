void test_radio_reciev() {
  while (ESC > 1120 || ESC < 1060) {

    //check shared flags to see if we have a new signal
    if (bUpdateFlagsShared) {
      noInterrupts();
      bUpdateFlags = bUpdateFlagsShared;
      if (bUpdateFlags & ESC_FLAG) {
        ESC = ESC_IN_SHARED;
      }
      if (bUpdateFlags & ELEVATOR_FLAG) {
        ELEVATOR = ELEVATOR_IN_SHARED;
      }
      if (bUpdateFlags & AILERON_FLAG) {
        AILERON = AILERON_IN_SHARED;
      }
      if (bUpdateFlags & ppp_flag) {
        ppp = ppp_in_shared;
      }

      bUpdateFlagsShared = 0;
      interrupts();

    }

    bUpdateFlags = 0;


  }
}



void check_radio_signal() {
  //check shared flags to see if we have a new signal
  if (bUpdateFlagsShared) {
    noInterrupts();
    bUpdateFlags = bUpdateFlagsShared;
    if (bUpdateFlags & ESC_FLAG) {
      ESC = ESC_IN_SHARED;
    }
    if (bUpdateFlags & ELEVATOR_FLAG) {
      ELEVATOR = ELEVATOR_IN_SHARED;
    }
    if (bUpdateFlags & AILERON_FLAG) {
      AILERON = AILERON_IN_SHARED;
    }
    if (bUpdateFlags & ppp_flag) {
      ppp = ppp_in_shared;
    }
    if (bUpdateFlags & ppp2_flag) {
      ppp2 = ppp2_in_shared;
    }

    if (bUpdateFlags & ppp3_flag) {
      ppp3 = ppp3_in_shared;
    }


    bUpdateFlagsShared = 0;
    interrupts();

  }

  bUpdateFlags = 0;




}
