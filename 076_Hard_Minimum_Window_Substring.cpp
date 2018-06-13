#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int cnt[128] = {0}, num = 0;
        for (char c : t) {
            num += (cnt[c]++ == 0);
        }
        int low = 0, minLen = INT_MAX, start = 0;
        for (int high = 0; high < s.size(); high++) {
            num -= (--cnt[s[high]] == 0);
            if (!num) {
                while (cnt[s[low]] < 0) {
                    cnt[s[low++]]++;
                }
                if (high - low + 1 < minLen) {
                    minLen = high - low + 1;
                    start = low;
                }
                cnt[s[low++]]++;num++;
            }
        }
        if (minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};
