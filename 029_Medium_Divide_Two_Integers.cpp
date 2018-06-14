#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        int symbol = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        int res = 0;
        long long dividendLong = labs(dividend), divisorLong = labs(divisor);

        while (dividendLong >= divisorLong) {
            long long tmp = divisorLong, mul = 1;
            while (dividendLong >= (tmp << 1)) {
                tmp <<= 1;
                mul <<= 1;
            }
            res += mul;
            dividendLong -= tmp;
        }
        return (symbol == 1) ? res : -res;
    }
};
