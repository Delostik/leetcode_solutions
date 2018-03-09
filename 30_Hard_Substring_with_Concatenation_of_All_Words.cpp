#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) {
            return res;
        }
        unordered_map<string, int> wordsMap;
        for (auto iter = words.begin(); iter != words.end(); iter++) {
            wordsMap[*iter]++;
        }
        int wordLength = words[0].size();
        unordered_map<string, int> windowMap;
        for (int offset = 0; offset < wordLength; offset++) {
            int head = offset;
            int matched = 0;
            for (int tail = offset; tail < s.size(); tail += wordLength) {
                string curStr = s.substr(tail , wordLength);
                if (wordsMap.count(curStr)) {
                    windowMap[curStr]++;
                    matched++;
                    if (windowMap[curStr] > wordsMap[curStr]) {
                        while (true) {
                            string headStr = s.substr(head, wordLength);
                            windowMap[headStr]--;
                            matched--;
                            head += wordLength;
                            if (headStr == curStr) {
                                break;
                            }
                        }
                    }
                    if (matched == words.size()) {
                        res.push_back(head);
                    }
                } else {
                    head = tail + wordLength;
                    matched = 0;
                    windowMap.clear();
                }
            }
            windowMap.clear();
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<string> words{"foo", "bar", "the"};
    auto res = solution->findSubstring("barfoofoobarthefoobarman", words);
    for (auto iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << endl;
    }
}