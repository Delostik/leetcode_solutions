#include <iostream>
#include <vector>

using namespace std;


struct Node {
    Node *next[26];
    bool isEnd;
};


class Solution {
public:
    string replaceWords(vector<string> &dict, string sentence) {
        Node *root = new Node(), *p;
        for (auto iter = dict.begin(); iter != dict.end(); iter++) {
            p = root;
            for (char c : *iter) {
                if (!p->next[c - 'a']) {
                    p->next[c - 'a'] = new Node();
                }
                p = p->next[c - 'a'];
            }
            p->isEnd = true;
        }

        string res = "", curWord = "";
        sentence += " ";

        for (char c : sentence) {
            if (c == ' ') {
                if (!curWord.empty()) {
                    p = root;
                    bool find = true;
                    for (char a:curWord) {
                        if (find && p->next[a - 'a']) {
                            p = p->next[a - 'a'];
                        } else {
                            find = false;
                        }

                        res += a;
                        if (find && p->isEnd) {
                            break;
                        }
                    }
                }
                curWord = "";
                res += c;
            } else {
                curWord += c;
            }
        }
        res.erase(res.size() - 1, 1);
        return res;
    }
};
