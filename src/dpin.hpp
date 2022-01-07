#include "types.hpp"

namespace aw109::rtu
{

    template <pin_t Pin>
    class DPin
    {
    private:
        int state;

    public:
        void begin()
        {
            pinMode(Pin, INPUT);
        }

        void tick()
        {
            state = digitalRead(Pin);
        }

        int get() const
        {
            return state;
        }
    };
} // namespace aw109::rtu
