/*
    题意：最长没有重复字母的子串
    解法：搞个窗口，长度255的bool数组判断出现过没
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool isExist[255] = {false};
        int head = 0, res = 0;
        for (int tail = 0; tail < s.size(); tail++) {
            int pos = s[tail];
            if (isExist[pos]) {
                for (; s[head] != pos; head++) {
                    isExist[s[head]] = false;
                }
                head++;
            }
            isExist[pos] = true;
            if (tail-head+1 > res) {
                res = tail - head + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << solution->lengthOfLongestSubstring("abcabcbb") << endl;
    cout << solution->lengthOfLongestSubstring("bbbbb") << endl;
    cout << solution->lengthOfLongestSubstring("pwwkew") << endl;
}