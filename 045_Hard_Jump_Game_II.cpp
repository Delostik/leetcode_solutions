#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int res = 0, nextMax = nums[0], curPos = 0;
        while (true) {
            if (nextMax >= nums.size() - 1) {
                return res + 1;
            }
            int tNextMax = 0, tNextPos = 0;
            for (int i = curPos; i <= nextMax; i++) {
                if (i + nums[i] > tNextMax) {
                    tNextMax = i + nums[i];
                    tNextPos = i;
                }
            }
            res++;
            nextMax = tNextMax;
            curPos = tNextPos;
        }
    }
};
