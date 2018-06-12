#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
private:
    int calcGCD(int a, int b) {
        return (b == 0) ? a : calcGCD(b, a % b);
    }

public:
    int maxPoints(vector<Point> &points) {
        int len = points.size();
        if (len < 2) {
            return len;
        }
        int max = 0;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                int cnt = 0;
                if (points[i].x == points[j].x) {
                    for (int k = 0; k < len; k++) {
                        if (points[k].x == points[i].x) {
                            cnt++;
                        }
                    }
                } else {
                    // y = (a1/a2)x + (b1/b2)
                    int gcd = calcGCD(points[i].y - points[j].y, points[i].x - points[j].x);
                    pair<int, int> a = make_pair((points[i].y - points[j].y) / gcd, (points[i].x - points[j].x) / gcd);
                    pair<int, int> b = make_pair(a.first * points[i].x + points[i].y * a.second, a.second);

                    for (int k = 0; k < len; k++) {
                        gcd = calcGCD(points[i].y - points[k].y, points[i].x - points[k].x);
                        if (gcd == 0) {
                            cnt += (points[i].x == points[k].x && points[i].y == points[k].y);
                            continue;
                        }
                        pair<int, int> _a = make_pair((points[i].y - points[k].y) / gcd,
                                                      (points[i].x - points[k].x) / gcd);
                        pair<int, int> _b = make_pair(a.first * points[i].x + points[i].y * a.second, a.second);
                        if (a == _a && b == _b) {
                            cnt++;
                        }
                    }
                }
                if (cnt > max) {
                    max = cnt;
                }
            }
        }
        return max;
    }
};
