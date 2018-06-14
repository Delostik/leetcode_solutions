#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int *f = new int[n+1];
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = 0;
            for (int j = 0; j < i;j++) {
                f[i] += f[j]*f[i-j-1];
            }
        }
        return f[n];
    }
};
