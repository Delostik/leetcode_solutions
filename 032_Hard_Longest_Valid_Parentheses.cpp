#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    const int LEFT_MARK = -1;
    int longestValidParentheses(string s) {
        s.erase(0, s.find_first_of('('));
        s.erase(s.find_last_of(')') + 1);
        stack<int> stk;
        int restLeft = 0;
        int res = 0;
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            if (*iter == '(') {
                restLeft++;
                stk.push(LEFT_MARK);
            } else {
                if (restLeft == 0) {
                    int curRes = 0;
                    while (!stk.empty()) {
                        curRes += stk.top();
                        stk.pop();
                    }
                    res = max(res, curRes);
                } else {
                    int curRes = 0;
                    while (stk.top() != -1) {
                        curRes += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    stk.push(curRes + 2);
                    restLeft--;
                }
            }
        }
        int curRes = 0;
        for (; !stk.empty(); stk.pop()) {
            if (stk.top() == -1) {
                res = max(res, curRes);
                curRes = 0;
            } else {
                curRes += stk.top();
            }
        }
        res = max(res, curRes);
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << solution->longestValidParentheses("()(()") << endl;
}