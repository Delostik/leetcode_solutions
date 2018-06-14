#include <iostream>
#include <vector>

#define PRESENT 0
#define LATE 1
#define ABSENT 2

using namespace std;

class Solution {
    long long f[100001][3][2];
    int modulo = 1000000007;
public:
    int checkRecord(int n) {
        memset(f, 0, sizeof(f));
        f[0][0][0] = 1;
        f[1][PRESENT][0] = f[1][LATE][0] = f[1][ABSENT][1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i][PRESENT][0] = f[i - 1][PRESENT][0] + f[i - 1][LATE][0];
            f[i][PRESENT][1] = f[i - 1][PRESENT][1] + f[i - 1][LATE][1] + f[i - 1][ABSENT][1];

            f[i][LATE][0] = f[i - 2][PRESENT][0] * 2 + f[i - 2][LATE][0];
            f[i][LATE][1] =
                    f[i - 2][PRESENT][1] * 2 + f[i - 2][LATE][1] + f[i - 2][ABSENT][1] * 2 + f[i - 2][PRESENT][0] +
                    f[i - 2][LATE][0];

            f[i][ABSENT][1] = f[i - 1][PRESENT][0] + f[i - 1][LATE][0];
            for (int j = 0; j < 3; j++) {
                f[i][j][0] %= modulo;
                f[i][j][1] %= modulo;
            }
        }
        long long res = 0;
        for (int j = 0; j < 3; j++) {
            res = (res + f[n][j][0]) % modulo;
            res = (res + f[n][j][1]) % modulo;
        }
        return (int)res;
    }
};
