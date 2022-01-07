#include <Arduino.h>

#include "rotary.hpp"
#include "button.hpp"
#include "potentiometer.hpp"
#include "dpin.hpp"
#include "apin.hpp"

#include "timer.hpp"

#include "buffer.hpp"
#include "protocol.hpp"

void begin_components();
void tick_components();
void update_component_buffers();
void reset_component_buffers();

aw109::rtu::Potentiometer<1> brightness;
aw109::rtu::RotaryEncoder<9, 10> inner_rotary;
aw109::rtu::RotaryEncoder<11, 12> outer_rotary;
aw109::rtu::Button<2> btnsx1;
aw109::rtu::Button<3> btnsx2;
aw109::rtu::Button<4> btnsx3;
aw109::rtu::Button<5> btnsx4;
aw109::rtu::Button<6> btndx1;
aw109::rtu::Button<7> btndx2;
aw109::rtu::Button<8> btndx3;
aw109::rtu::DPin<0> d0;
aw109::rtu::DPin<1> d1;
aw109::rtu::APin<0> a0;
aw109::rtu::APin<2> a2;
aw109::rtu::APin<3> a3;
aw109::rtu::APin<4> a4;
aw109::rtu::APin<5> a5;
aw109::rtu::APin<6> a6;
aw109::rtu::APin<7> a7;

aw109::rtu::Timer<50> timer;

aw109::rtu::RoundBuffer<int, 0, 5> brightness_buffer;
aw109::rtu::Buffer<int, 0, 2> inner_rotary_buffer(0, (int[]){-1, +1});
aw109::rtu::Buffer<int, 0, 2> outer_rotary_buffer(0, (int[]){-1, +1});
aw109::rtu::Buffer<int, 0, 2> btnsx1_buffer(0, (int[]){1, -1});
aw109::rtu::Buffer<int, 0, 2> btnsx2_buffer(0, (int[]){1, -1});
aw109::rtu::Buffer<int, 0, 2> btnsx3_buffer(0, (int[]){1, -1});
aw109::rtu::Buffer<int, 0, 2> btnsx4_buffer(0, (int[]){1, -1});
aw109::rtu::Buffer<int, 0, 2> btndx1_buffer(0, (int[]){1, -1});
aw109::rtu::Buffer<int, 0, 2> btndx2_buffer(0, (int[]){1, -1});
aw109::rtu::Buffer<int, 0, 2> btndx3_buffer(0, (int[]){1, -1});

String last_msg = "";

void setup()
{
    Serial.begin(9600);
    begin_components();
}

void loop()
{
    tick_components();

    timer.tick(millis());

    update_component_buffers();

    if (timer.is_expired())
    {
        timer.reset();

        String msg = aw109::rtu::protocol::get_notify_message(
            brightness_buffer.get(),
            inner_rotary_buffer.get(),
            outer_rotary_buffer.get(),
            btnsx1_buffer.get(),
            btnsx2_buffer.get(),
            btnsx3_buffer.get(),
            btnsx4_buffer.get(),
            btndx1_buffer.get(),
            btndx2_buffer.get(),
            btndx3_buffer.get(),
            d0.get(),
            d1.get(),
            a0.get(),
            a2.get(),
            a3.get(),
            a4.get(),
            a5.get(),
            a6.get(),
            a7.get());

        if (msg != last_msg)
            aw109::rtu::protocol::send(msg);

        last_msg = msg;

        reset_component_buffers();
    }
}

void begin_components()
{
    brightness.begin();
    inner_rotary.begin();
    outer_rotary.begin();
    btnsx1.begin();
    btnsx2.begin();
    btnsx3.begin();
    btnsx4.begin();
    btndx1.begin();
    btndx2.begin();
    btndx3.begin();
    d0.begin();
    d1.begin();
    a0.begin();
    a2.begin();
    a3.begin();
    a4.begin();
    a5.begin();
    a6.begin();
    a7.begin();
}

void tick_components()
{
    brightness.tick();
    inner_rotary.tick();
    outer_rotary.tick();
    btnsx1.tick();
    btnsx2.tick();
    btnsx3.tick();
    btnsx4.tick();
    btndx1.tick();
    btndx2.tick();
    btndx3.tick();
    d0.tick();
    d1.tick();
    a0.tick();
    a2.tick();
    a3.tick();
    a4.tick();
    a5.tick();
    a6.tick();
    a7.tick();
}

void update_component_buffers()
{
    brightness_buffer.set(brightness.get());
    inner_rotary_buffer.set(inner_rotary.get());
    outer_rotary_buffer.set(outer_rotary.get());
    btnsx1_buffer.set(btnsx1.get());
    btnsx2_buffer.set(btnsx2.get());
    btnsx3_buffer.set(btnsx3.get());
    btnsx4_buffer.set(btnsx4.get());
    btndx1_buffer.set(btndx1.get());
    btndx2_buffer.set(btndx2.get());
    btndx3_buffer.set(btndx3.get());
}

void reset_component_buffers()
{
    inner_rotary_buffer.reset();
    outer_rotary_buffer.reset();
    btnsx1_buffer.reset();
    btnsx2_buffer.reset();
    btnsx3_buffer.reset();
    btnsx4_buffer.reset();
    btndx1_buffer.reset();
    btndx2_buffer.reset();
    btndx3_buffer.reset();
}
