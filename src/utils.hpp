#include "types.hpp"

namespace aw109::rtu
{
    template <typename T>
    bool contains(T *(&a), size_t n, T x)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                return true;
            }
        }
        return false;
    }

} // namespace aw109::rtu
