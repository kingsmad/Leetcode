/*************************************************************************
    > File Name: 132.Palindrome Partitioning II.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Mon Apr  6 22:26:12 2015
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if(len < 1)
            return 0;
        bool dp[len][len];
        for(int i=0; i<len; ++i)
            dp[i][i] = true;
        for(int i=0; i+1<len; ++i) 
            dp[i][i+1] = (s[i] == s[i+1]);
        
        for(int ost=2; ost<len; ++ost) {
            for(int i=0; i+ost<len; ++i) {
                dp[i][i+ost] = (s[i] == s[i+ost] && dp[i+1][i+ost-1]);
            }
        }
        
        int ans[len];
        for(int i=0; i<len; ++i) {
            if(dp[0][i]) {
                ans[i] = 0;
                continue;
            }
            int res = len - 1;
            for(int j=i; j>=0; --j) {
                if(dp[j][i]) {
                    res = min(res, ans[j-1] + 1);
                }
            }
            ans[i] = res;
        }

        return ans[len-1];
    }
};

int main(int argc, char** argv) {
    string s1;
    Solution sol;
    cin >> s1;
    
    int ans = sol.minCut(s1);

    cout << "The answer is: " << ans << endl;

    return 0;
}
