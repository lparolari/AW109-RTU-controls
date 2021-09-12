#include "utils.hpp"

namespace aw109::rtu
{
    template <typename T, T Value, size_t N>
    class Buffer
    {
    private:
        T value = Value;
        T *significants;

    public:
        Buffer(T value, T *significants) : value(value), significants(significants) {}

        void set(T value)
        {
            if (contains(significants, N, value))
            {
                this->value = value;
            }
        }

        T get() const
        {
            return value;
        }

        void reset()
        {
            value = Value;
        }
    };
} // namespace aw109::rtu
