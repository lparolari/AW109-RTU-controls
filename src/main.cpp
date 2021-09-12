#include <Arduino.h>

#include <rotary.hpp>
#include <buffer.hpp>
#include <timer.hpp>
#include <button.hpp>

aw109::rtu::RotaryEncoder<11, 12> rotary;
aw109::rtu::Timer<10> timer;
aw109::rtu::Button<2> button;

aw109::rtu::Buffer<int, 0, 2> rotary_buffer(0, (int[]){-1, +1});
aw109::rtu::Buffer<int, 0, 2> btn_sx1_buffer(0, (int[]){1, -1});

void setup()
{
  Serial.begin(9600);

  rotary.begin();
  button.begin();
}

void loop()
{
  rotary.tick();
  button.tick();

  timer.tick(millis());

  rotary_buffer.set(rotary.get());
  btn_sx1_buffer.set(button.get());

  if (timer.is_expired())
  {
    Serial.print(rotary_buffer.get());
    Serial.print(",");
    Serial.println(btn_sx1_buffer.get());

    rotary_buffer.reset();
    btn_sx1_buffer.reset();
    timer.reset();
  }
}
