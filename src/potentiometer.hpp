#include "types.hpp"

namespace aw109::rtu
{
    template <pin_t Pin, typename T = int, T Initial = 0>
    class Potentiometer
    {
    private:
        T state = Initial;

    public:
        void begin() {}

        void tick()
        {
            state = analogRead(Pin);
        }

        T get() const
        {
            return state;
        }
    };
} // namespace aw109::rtu
