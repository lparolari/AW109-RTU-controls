#include "Arduino.h"

namespace aw109::rtu::protocol
{
    String get_notify_message(int brightness, int inner_rotary, int outer_rotary, int btnsx1, int btnsx2, int btnsx3, int btnsx4,
                              int btndx1, int btndx2, int btndx3)
    {
        String msg = "";

        msg += String(brightness);
        msg += ",";
        msg += String(inner_rotary);
        msg += ",";
        msg += String(outer_rotary);
        msg += ",";
        msg += String(btnsx1);
        msg += ",";
        msg += String(btnsx2);
        msg += ",";
        msg += String(btnsx3);
        msg += ",";
        msg += String(btnsx4);
        msg += ",";
        msg += String(btndx1);
        msg += ",";
        msg += String(btndx2);
        msg += ",";
        msg += String(btndx3);

        return msg;
    }

    void send(String msg)
    {
        Serial.println(msg);
    }
} // namespace aw109::rtu::protocol
