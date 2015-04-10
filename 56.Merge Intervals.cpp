/*************************************************************************
    > File Name: 56.Merge Intervals.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  9 13:27:36 2015
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
template <class T>
class Ksless : public binary_function<T, T, bool> {
public:
    bool operator()(const T& t1, const T& t2) {
        return t1.start < t2.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), Ksless<Interval>());
        int len = intervals.size();
        vector<Interval> ans;
        for(int i=0; i<len; ) {
            Interval cur = intervals[i];
            int k = i + 1;
            while(k < len && intervals[k].start <= \
                    cur.end) {
                cur.end = max(intervals[k].end, cur.end); 
                ++k;
            }
            ans.push_back(cur); 
            i = k;
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    fstream in("/Users/Archer/Desktop/dat.txt");
    cin.rdbuf(in.rdbuf());
    int len;
    cin >> len;
    vector<Interval> intervals(len, Interval());
    for(int i=0; i<len; ++i) {
        cin >> intervals[i].start; 
        cin >> intervals[i].end;
    }


    Solution sol;
    vector<Interval> ans = sol.merge(intervals);
    for(int i=0; i<ans.size(); ++i) 
        printf("[%d, %d] ", ans[i].start, ans[i].end);

    cout << endl; 
    return 0;
}
