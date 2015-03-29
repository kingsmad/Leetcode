#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    	if(height.empty())
    		return 0;

    	height.push_back(0);
    	stack<int> istack;
    	int ans = 0;

    	for(int i=0; i<height.size(); ++i) {
    		if(istack.empty() || height[i] >= height[istack.top()])
    			istack.push(i);
    		else {
    			while(!istack.empty() && height[istack.top()] >= height[i]) {
    				int p = istack.top();
    				istack.pop();
    				int tmp = height[p] * (istack.empty() ? i : i-istack.top()-1);
    				/*关于序号，若余下stack为空，istack.top()就不存在*/
    				ans = max(ans, tmp);
    			}
    			istack.push(i);
    		}
    	}

    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	int len;
	cin >> len;
	vector<int> height(len);
	for(int i=0; i<len; ++i) {
		cin >> height[i];
	}

	Solution sol;
	int ans = sol.largestRectangleArea(height);

	cout << ans << endl;
	return 0;
}