#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int low = 0, high = height.size() - 1, res = 0;
        while (low < high) {
            res = max(res, min(height[high], height[low]) * (high - low));
            if (height[low] > height[high]) {
                high--;
            } else {
                low++;
            }
        }
        return res;
    }
};
