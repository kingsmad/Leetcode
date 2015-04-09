/*************************************************************************
    > File Name: 32.Longest Valid Parentheses.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  9 23:11:47 2015
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

/*Congratulations! - -
when stack is empty & we met '(' ===> we should re-consider first
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mstack;
        int len = s.size();
        int ans = 0;
        int first = 0;
        bool dirty = false;
        for(int i=0; i<len; ++i) {
            if(s[i] == '(') {
            	mstack.push(i);
            	if(dirty){
            		dirty = false;
            		first = i;
            	}
            }
            else {
            	if(!mstack.empty()) {
            		mstack.pop();
            		int t = mstack.empty() ? first : mstack.top()+1;
            		ans = max(ans, i - t + 1);
            	} else {
            		dirty = true;
            	}
            }
        }

        return ans;
    }
};

int main(int argc, char** argv ) {
    string s;
    cin >> s;
    Solution sol;
    int ans = sol.longestValidParentheses(s);

    cout << "The answer is:" << ans << endl;

    return 0;
}
