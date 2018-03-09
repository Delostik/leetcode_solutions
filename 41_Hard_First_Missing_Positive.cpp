#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int minPositive = 2147483647;
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0 && nums[i] < minPositive) {
                minPositive = nums[i];
            }            
        }
        if (minPositive > 1) {
            return 1;
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] < 0 || nums[i] > size) {
                nums[i] = 0;
            } else {
                while (nums[i] != i+1 && nums[i] > 0) {
                    if (nums[nums[i]-1] == nums[i]) {
                        nums[i] = 0;
                        break;
                    }
                    int t = nums[i];
                    nums[i] = nums[nums[i]-1];
                    nums[t-1] = t;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return size+1;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums{3, 4, 1, -1};
    cout << solution->firstMissingPositive(nums) << endl;
}