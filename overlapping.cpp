#include <iostream>
#include <vector>

using namespace std;

 class Interval {
 public:
 	int start;
 	int end;
 	Interval() : start(0), end(0) {}
 	Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        int i = 0;
        int len = intervals.size();

        while(true) {
        	if(i < len && intervals[i].end < newInterval.start) {
        		ans.push_back(intervals[i]);
        		++i;
        	}
        	else
        		break;
        }
        if(i == len) {
        	ans.push_back(newInterval);
        	return ans;
        }

        Interval tmp;
        if(newInterval.start < intervals[i].start)
        	tmp.start = newInterval.start;
        else 
        	tmp.start = intervals[i].start;

        while(true) {
        	if(i < len && intervals[i].end < newInterval.end) {
        		++i;
        	}
        	else
        		break;
        }

        if(i == len ) {
        	tmp.end = newInterval.end;
        	ans.push_back(tmp);
        	return ans;
        }


        if(newInterval.end < intervals[i].start) {
        	tmp.end = newInterval.end;
        }
        else {
        	tmp.end = intervals[i].end;
        	++i;
        }

        ans.push_back(tmp);
        for(; i<len; ++i) {
        	ans.push_back(intervals[i]);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
	vector<Interval> intervals;
	int int_len;
	cin >> int_len;

	Interval tmp;
	while(int_len--) {
		cin >> tmp.start;
		cin >> tmp.end;
		intervals.push_back(tmp);
	}

	Interval ne ;
	cin >> ne.start;
	cin >> ne.end;


	Solution sol;
	vector<Interval> ans = sol.insert(intervals, ne);

	for(int i=0; i<ans.size(); ++i) {
		cout << ans[i].start << " " << ans[i].end << "   ";
	}
	return 0;
}