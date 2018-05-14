#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int res = 0, i = 0, j = 0;

        while (i < height.size()) {
            for (j = i + 1; j < height.size(); j++) {
                if (height[j] >= height[i]) {
                    break;
                }
            }
            if (j >= height.size()) {
                break;
            }
            for (int k = i + 1; k < j; k++) {
                res += height[i] - height[k];
            }
            i = j;
        }

        i = height.size() - 1;
        while (i > 0) {
            for (j = i - 1; j >= 0; j--) {
                if (height[j] > height[i]) {
                    break;
                }
            }
            if (j < 0) {
                break;
            }
            for (int k = i - 1; k > j; k--) {
                res += height[i] - height[k];
            }
            i = j;
        }

        return res;
    }
};
