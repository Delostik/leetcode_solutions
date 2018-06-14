#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res = "";
        int skip1, skip2;
        for (int i = 0; i < numRows; i++) {
            skip1 = 2 * numRows - 2 * i - 2;
            skip2 = 2 * i;
            for (int j = i, cnt = 1; j < s.size(); cnt++) {
                res += s[j];
                if (!skip1 || !skip2) j += skip1 + skip2;
                else if (cnt & 1 && skip1) j += skip1;
                else if (!(cnt & 1) && skip2) j += skip2;
            }
        }
        return res;
    }
};
