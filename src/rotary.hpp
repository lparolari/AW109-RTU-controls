#include "types.hpp"

namespace aw109::rtu
{
    /**
     * Source https://www.giuseppecaccavale.it/arduino/rotary-encoder-arduino/
     */
    template <pin_t PinA = 0, pin_t PinB = 0, typename T = int>
    class RotaryEncoder
    {
    private:
        int last_a = 0;
        int value = 0;
        int direction = 0;

    public:
        void begin()
        {
            pinMode(PinA, INPUT_PULLUP);
            pinMode(PinB, INPUT_PULLUP);

            last_a = digitalRead(PinA);
        }

        void tick()
        {
            int a = digitalRead(PinA);

            if (a != last_a)
            {
                int b = digitalRead(PinB);
                if (b != a)
                {
                    value++;
                    direction = 1;
                }
                else
                {
                    value--;
                    direction = -1;
                }

                // Serial.print("Encoder value = ");
                // Serial.println(value);
            }
            else
            {
                direction = 0;
            }

            last_a = a;
        }

        T get() const
        {
            return direction;
        }
    };
} // namespace aw109::rtu
