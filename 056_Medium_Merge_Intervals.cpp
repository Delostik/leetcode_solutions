#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static int cmp(Interval &a, Interval &b) {
        if (a.start == b.start) {
            return a.end < b.end;
        }
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size(); i++) {
            Interval interval(intervals[i].start, intervals[i].end);
            while (i+1<intervals.size() && intervals[i+1].start <= interval.end) {
                i++;
                interval.end = max(interval.end, intervals[i].end);
            }
            res.push_back(interval);
        }
        return res;
    }
};
