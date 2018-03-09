/*
    题意：数组中找倆数x,y使得x+y=z（给定的z）
    解法：枚举
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> res;
        for (int x = 0; x < length-1; x++) {
            for (int y = x+1; y < length; y++) {
                if (nums[x] + nums[y] == target) {
                    return vector<int>{x,y};
                }
            }
        }
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums{3,2,4};
    int target = 6;
    auto res = solution->twoSum(nums, target);
    for (auto iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}
