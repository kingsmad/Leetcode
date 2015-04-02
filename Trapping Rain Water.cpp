/*************************************************************************
    > File Name: Trapping Rain Water.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  2 14:30:49 2015
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    int trap(int A[], int n) {
	int ans = 0;
	if(!A)
	    return 0;
	int first = 0;
	while(first < n) {
	    int last = first;
	    while(last<n && A[first] >= A[last]) 
		++last;
	    if(last < n) {
		for(int i=first; i<last; ++i)
		    ans += A[first] - A[i];
		first = last;
	    } else 
		break;	
	}
	
	stack<int> mstack;
	mstack.push(n-1);
	for(int i=n-1; i>first; --i) {
	    int t = mstack.top();
	    if(A[t] > A[i])
		mstack.push(t);
	    else
		mstack.push(i);
	}

	while(!mstack.empty()) {
	    int t = mstack.top();
	    for(int i=first+1; i<=t; ++i)
		ans += A[t] - A[i]; 
	    first = t;
	    while(!mstack.empty() && mstack.top() == t)
			mstack.pop();
	}

	return ans;
    }
};

// another ac solution
/*class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(A == NULL || n < 3)
        	return 0;
        int totalWater = 0;

        int first = 0;
        while(A[first] < A[first+1] && first < n-1)
            ++first;
        if(first == n-1)
            return 0;

        int cur = first;
        while(true) {
            int next = cur + 1;
            while(next < n && A[next] < A[cur] )
                ++next;
            if(next == n)
                break;
            else {
                for(int i=cur; i<next; ++i) {
                    totalWater += A[cur] - A[i];
                }
                cur = next;
            }
        }

        while(cur < n-1) {
            int next = cur + 1;
            for(int i=cur+1; i<n; ++i)
                if(A[i] > A[next])
                    next = i;
            for(int i=cur+1; i<=next; ++i){
                totalWater += A[next] - A[i];
            }
            cur = next;
        }

        return totalWater;
    }
};
*/

int main(int argc, char** argv) {
    int len;
    cin >> len;
    int A[len];
    for(int i=0; i<len; ++i)
	cin >> A[i];
    Solution sol;
    int ans = sol.trap(A, len);
    cout << "\nThe ans is: " << ans << endl;
}




