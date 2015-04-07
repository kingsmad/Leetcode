/*************************************************************************
    > File Name: 84.Largest Rectangle in Histogram.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Mon Apr  6 12:40:25 2015
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size() < 1)
            return 0;
        height.push_back(0);
        stack<int> mstack;
        int len = height.size();
        int ans = 0;
        
        for(int i=0; i<len; ++i) {
            if(mstack.empty() || height[i] >= height[mstack.top()]) {
                mstack.push(i);
            }
            else {
                while(!mstack.empty() && \
                        height[mstack.top()] >= height[i]) {
                    int cur = mstack.top();
                    mstack.pop();
                    int left = mstack.empty() ? 0 : mstack.top()+1;
                    ans = max(ans, (i - left) * height[cur]);
                }
                mstack.push(i);
            }
        }

        height.pop_back();
        return ans;
    }
};

int main(int argc, char** argv) {
    int len ;
    cin >> len;
    vector<int> vec(len);
    for(int i=0; i<len; ++i) 
        cin >> vec[i];

    Solution sol;
    int ans = sol.largestRectangleArea(vec);

    cout << "Answer is: " << ans << endl;
}
