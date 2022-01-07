#include "types.hpp"

namespace aw109::rtu
{

    template <pin_t Pin>
    class APin
    {
    private:
        int state;

    public:
        void begin()
        {
        }

        void tick()
        {
            state = analogRead(Pin);
        }

        int get() const
        {
            return state;
        }
    };
} // namespace aw109::rtu
