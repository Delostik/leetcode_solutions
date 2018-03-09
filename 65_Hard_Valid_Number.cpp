#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        trim(s);
        if (s.empty()) {
            return false;
        }

        auto exp = s.find("e");
        if (exp != string::npos) {
            string left = s.substr(0, exp), right = s.substr(exp+1);
            removeSymbol(left);
            removeSymbol(right);
            return !left.empty() && isFloat(left) && !right.empty() && isInt(right);
        }
        removeSymbol(s);
        return isFloat(s);
    }
private:
    void trim(string &s) {
        if (!s.empty()) {
            s.erase(0, s.find_first_not_of(" "));  
            s.erase(s.find_last_not_of(" ") + 1);  
        }
    }

    void removeSymbol(string &s) {
        if (s[0] == '+' || s[0] == '-') {
            s.erase(s.begin());
        }
    }

    bool isInt(string &s) {
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            if (*iter < '0' || *iter > '9') {
                return false;
            }
        }
        return true;
    }

    bool isFloat(string &s) {
        auto dot = s.find(".");
        if (dot == string::npos) {
            return isInt(s);
        }
        string left = s.substr(0, dot);
        string right = s.substr(dot+1);
        return isInt(left) && isInt(right) && (!left.empty() || !right.empty());
    }
};

int main() {
    Solution *solution = new Solution();
    cout << solution->isNumber("0.01 a ") << endl;
}