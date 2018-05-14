#include <iostream>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] == '.') {
                int j = i;
                while (j + 1 < dominoes.size() && dominoes[j + 1] == '.') {
                    j++;
                }

                char left = (i == 0) ? 'L' : dominoes[i - 1];
                char right = (j == dominoes.size() - 1) ? 'R' : dominoes[j + 1];
                int leftPos = i, rightPos = j;
                while (leftPos < rightPos) {
                    bool moved = false;
                    if (left == 'R') {
                        dominoes[leftPos++] = 'R';
                        moved = true;
                    }
                    if (right == 'L') {
                        dominoes[rightPos--] = 'L';
                        moved = true;
                    }
                    if (!moved) {
                        break;
                    }
                }
                if (leftPos == rightPos) {
                    dominoes[leftPos] = (left == right) ? left : '.';
                }
                i = j;
            }
        }
        return dominoes;
    }
};
