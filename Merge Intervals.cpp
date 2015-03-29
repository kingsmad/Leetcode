#include <iostream>
#include <vector>
#include <functional>


using namespace std;
template<class T>
struct Compare : public binary_function<T, T, bool> {
	bool operator() (const T& t1, const T& t2) {
		return t1.start < t2.start;
	}
};

 struct Interval {
 	int start;
 	int end;
	Interval() : start(0), end(0) {}
 	Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        ans_.clear();
        sort(intervals.begin(), intervals.end(), Compare<Interval>());
        int len = intervals.size();
        for(int i=0; i<len; ) {
        	int start = intervals[i].start;
        	int end = intervals[i].end;
        	int pv = i + 1;
        	
        	while(pv < len) {
        		if(intervals[pv].start <= end) {
        			end = max(intervals[pv].end, end);
        			++pv;
        		}
        		else
        			break;
        	}
        	ans_.push_back(Interval(start, end));
        	i = pv;
        }

        return ans_;
    }
private:
	vector<Interval> ans_;
};

int main(int argc, char const *argv[])
{
	int len ;
	cin >> len;

	int st, ed;
	vector<Interval> ints;
	for(int i=0; i<len; ++i) {
		cin >> st;
		cin >> ed;
		ints.push_back(Interval(st, ed));
	}

	Solution sol;
	vector<Interval> ans = sol.merge(ints);

	for(int i=0; i<ans.size(); ++i) {
		cout << ans[i].start << " " << ans[i].end << endl;
	}
	return 0;
}