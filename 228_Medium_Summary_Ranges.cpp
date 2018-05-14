#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1) {
                j++;
            }
            if (i!=j) {
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            } else {
                res.push_back(to_string(nums[i]));
            }
            i = j;
        }
        return res;
    }
};
