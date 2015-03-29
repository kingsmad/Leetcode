#include <stack>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if(len < 2 )
            return 0;
        
        stack<int> istack;
        int ans = 0;
        int start = 0; //

        for(int i=0; i<s.size(); ++i) {
        	if(s[i] == '(') {
        		istack.push(i);
        	}
        	else {
        		if(istack.empty()) {
        			start = i+1; //如果已经空了，则更新起点到i+1；
        		}
        		else {
        			int t = istack.top();
        			istack.pop();
        			if(istack.empty()) { //如果已经空了，则以起点为准
        				ans = max(ans, i-start+1);
        			}
        			else { //此时没有空，前一个(的位置的下一个就是当前匹配的起点
        				ans = max(ans, i-istack.top());
        			}
        		}
        	}
        }


        return ans;
    }
};

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;

	Solution sol;
	int ans = sol.longestValidParentheses(s);

	cout << "ans is : " << ans << endl;
	return 0;
}