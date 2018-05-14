#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string> &words) {
        vector<const char *> waitList[26];
        int res = 0;
        for (string &word: words) {
            waitList[word[0] - 'a'].push_back(word.c_str());
        }
        
        for (auto c : S) {
            auto iter = waitList[c - 'a'];
            waitList[c - 'a'].clear();
            for (auto word: iter) {
                if (word[1] == 0) {
                    res++;
                } else {
                    waitList[word[1] - 'a'].push_back(word + 1);
                }
            }
        }
        return res;
    }
};

