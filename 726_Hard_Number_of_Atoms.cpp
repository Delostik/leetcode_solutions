#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumeric(string &s) {
        return s[0] >= '0' && s[0] <= '9';
    }

    string countOfAtoms(string formula) {
        vector<string> tokens;
        stack<pair<string, int> > stk;
        stack<pair<string, int> > temp;
        map<string, int> count;

        string curToken = "";
        int lastType = -1;  // 0: A, 1: a, 2: (), 3: Num
        for (int i = 0; i < formula.size(); i++) {
            char c = formula[i];
            int curType = (c >= 'A' && c <= 'Z') ? 0 : (c >= 'a' && c <= 'z') ? 1 : (c == '(' || c == ')') ? 2 : 3;
            if (!(lastType == -1 || (lastType == 3 && lastType == curType) || (lastType == 0 && curType == 1))) {
                tokens.push_back(curToken);
                curToken = "";
            }
            lastType = curType;
            curToken += c;
        }
        tokens.push_back(curToken);

        string::size_type size;
        int mul;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "(") {
                stk.push(make_pair(tokens[i], 0));
            } else if (tokens[i] == ")") {
                mul = 1;
                if (i + 1 < tokens.size() && isNumeric(tokens[i + 1])) {
                    mul = stoi(tokens[i + 1], &size);
                    i++;
                }
                while (stk.top().first != "(") {
                    pair<string, int> atom = stk.top();
                    stk.pop();
                    atom.second *= mul;
                    temp.push(atom);
                }
                stk.pop();
                while (!temp.empty()) {
                    stk.push(temp.top());
                    temp.pop();
                }
            } else {
                stk.push(make_pair(tokens[i], 1));
                if (i + 1 < tokens.size() && isNumeric(tokens[i + 1])) {
                    stk.top().second = stoi(tokens[++i], &size);
                }
            }
        }

        while(!stk.empty()) {
            if (count.find(stk.top().first) == count.end()) {
                count[stk.top().first] = stk.top().second;
            } else {
                count[stk.top().first] += stk.top().second;
            }
            stk.pop();
        }

        string res = "";
        for (auto x:count) {
            res += x.first;
            if (x.second > 1) {
                res += to_string(x.second);
            }
        }
        
        return res;
    }
};
