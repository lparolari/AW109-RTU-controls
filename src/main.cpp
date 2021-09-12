#include <Arduino.h>

#include <rotary.hpp>
#include <buffer.hpp>
#include <timer.hpp>

aw109::rtu::RotaryEncoder<11, 12> rotary;
aw109::rtu::Timer<1000> timer;

aw109::rtu::Buffer<int, 0, 2> rotary_buffer(0, (int[]){-1, +1});

void setup()
{
  Serial.begin(9600);
  rotary.begin();
}

void loop()
{
  unsigned long ms = millis();

  rotary.tick();
  timer.tick(ms);

  rotary_buffer.set(rotary.get());

  if (timer.is_expired())
  {
    Serial.println(rotary_buffer.get());

    rotary_buffer.reset();
    timer.reset();
  }
}
