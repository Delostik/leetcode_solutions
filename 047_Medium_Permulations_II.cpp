#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void search(vector<int> nums, int start, vector<vector<int>> &allPermulation) {
        if (start == nums.size()-1) {
            allPermulation.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i == start || nums[start] != nums[i]) {
                swap(nums[start], nums[i]);
                search(nums, start+1, allPermulation);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        search(nums, 0, res);
        return res;
    }
};
