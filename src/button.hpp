#include "types.hpp"

namespace aw109::rtu
{

    template <pin_t Pin, typename T = int, T Initial = 0, bool Inverted = false>
    class Button
    {
    private:
        T state = get_state(Initial);
        T last_state = get_state(Initial);

        int get_state(T state)
        {
            if (Inverted)
                state = !state;

            return state;
        }

    public:
        void begin()
        {
            pinMode(Pin, INPUT_PULLUP);
        }

        void tick()
        {
            last_state = state;
            state = get_state(digitalRead(Pin));
        }

        // 1 = pressed, -1 =  released
        T get() const
        {
            if (last_state - state > 0)
                return 1;
            if (last_state - state < 0)
                return -1;
            return 0;
        }
    };
} // namespace aw109::rtu
