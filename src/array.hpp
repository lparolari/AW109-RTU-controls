#include "utils.hpp"

namespace aw109::rtu
{
    template <typename T, size_t N>
    class Array

    {
    private:
        T data[N];

    public:
        Array(T (&arr)[N])
        {
            for (size_t i = 0; i < N; i++)
            {
                this->data[i] = data[i];
            }
        }
    };
} // namespace aw109::rtu
