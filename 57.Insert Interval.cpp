/*************************************************************************
    > File Name: 57.Insert Interval.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  9 12:57:06 2015
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        int len = intervals.size();
        int cur = 0;
        while(cur < len && intervals[cur].end \
                < newInterval.start) {
            ans.push_back(intervals[cur]); 
            ++cur;
        }
        while(cur < len && !(intervals[cur].end < \
            newInterval.start || intervals[cur].start >\
            newInterval.end) ) {
            newInterval.start = min(intervals[cur].start, \
                    newInterval.start);
            newInterval.end = max(intervals[cur].end, \
                    newInterval.end);
            ++cur;
        }
        ans.push_back(newInterval);
        
        while(cur < len) {
            ans.push_back(intervals[cur]);
            ++cur;
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    int len;
    cin >> len;
    vector<Interval> intervals(len, Interval());
    for(int i=0; i<len; ++i) {
        cin >> intervals[i].start; 
        cin >> intervals[i].end;
    }

    printf("Please enter your newInterval:\n");
    Interval newInterval;
    cin >> newInterval.start;
    cin >> newInterval.end;

    Solution sol;
    vector<Interval> ans = sol.insert(intervals, newInterval);
    for(int i=0; i<ans.size(); ++i) 
        printf("[%d, %d] ", ans[i].start, ans[i].end);

    cout << endl; 
    return 0;
}
