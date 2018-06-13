#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 > len2) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = 2 * len1, mid1, mid2,l1, l2, r1, r2;
        while (low <= high) {
            mid1 = (low + high) >> 1;
            mid2 = len1 + len2 - mid1;
            l1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
            l2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            r1 = (mid1 == len1 * 2) ? INT_MAX : nums1[mid1 / 2];
            r2 = (mid2 == len2 * 2) ? INT_MAX : nums2[mid2 / 2];
            if (l1 > r2) high = mid1 - 1;
            else if (l2 > r1) low = mid1 + 1;
            else return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
    }
};
