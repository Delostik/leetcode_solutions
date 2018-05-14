#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define min3(a, b, c) min(min(a,b),c)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int **f = new int *[word1.size() + 1];
        for (int i = 0; i <= word1.size(); i++) {
            f[i] = new int[word2.size() + 1];
            memset(f[i], 0, sizeof(f[i]));
        }
        for (int i = 1; i <= word1.size(); i++) {
            f[i][0] = i;
        }
        for (int j = 1; j <= word2.size(); j++) {
            f[0][j] = j;
        }

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = min3(f[i-1][j]+1, f[i-1][j-1]+1, f[i][j-1]+1);
                }
            }
        }
        return f[word1.size()][word2.size()];
    }
};
