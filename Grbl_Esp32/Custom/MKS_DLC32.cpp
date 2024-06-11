/*
machine_init() is called when Grbl_ESP32 first starts. You can use it to do any
special things your machine needs at startup.
*/
#include <Arduino.h>

void machine_init() {
    // force this on all the time
    grbl_msg_sendf(CLIENT_SERIAL, MsgLevel::Info, "Custom machine_init() Level Shift Enabled");
    pinMode(LVL_SHIFT_ENABLE, OUTPUT);
    digitalWrite(LVL_SHIFT_ENABLE, HIGH);
}
