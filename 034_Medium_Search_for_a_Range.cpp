#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int head = lowerBound(nums, target);
        if (head < nums.size() && nums[head] == target) {
            return {head, lowerBound(nums, target + 1) - 1};
        }
        return {-1, -1};
    }

    int lowerBound(vector<int> &nums, int target) {
        int head = 0, tail = nums.size() - 1, mid;
        while (head <= tail) {
            mid = (head + tail) >> 1;
            if (nums[mid] < target) head = mid + 1;
            else tail = mid - 1;
        }
        return head;
    }
};

