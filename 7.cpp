#include <limits>
class Solution {
public:
    int reverse(int x) {
        bool minus = x < 0;
        x = std::abs(x);
        int64_t result = 0;
        while (x > 0)
        {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        if (result > std::numeric_limits<int32_t>::max())
            return 0;
        result *= minus ? -1 : 1;
        return static_cast<int32_t>(result);
    }
};