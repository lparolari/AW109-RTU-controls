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

    template <typename T, T DefaultValue, T AbsoluteStep>
    class RoundBuffer
    {
    private:
        T value = DefaultValue;
        T last = DefaultValue;

    public:
        T get() const
        {
            return value;
        }

        void set(T value)
        {
            if (abs(this->last - value) > AbsoluteStep)
            {
                this->last = this->value;
                this->value = value;
            }
        }
    };
} // namespace aw109::rtu
