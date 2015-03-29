
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        bool dp[len][len];

        for(int i=0; i<len; ++i)
            dp[i][i] = true;

        for(int i=0; i<len-1; ++i) {
            if(s[i] == s[i+1])
                dp[i][i+1] = true;
            else 
                dp[i][i+1] = false;
        }

        for(int offset=2; offset<len; ++offset) {
            for(int k=0; k+offset<len; ++k) {
                if(s[k] != s[k+offset])
                    dp[k][k+offset] = false;
                else
                    dp[k][k+offset] = dp[k+1][k+offset-1];
            }
        }

        int ans[len];
        ans[0] = 0;

        for(int i=1; i<len; ++i) {
            if(dp[0][i]) {
                ans[i] = 0;
                continue;
            }
            ans[i] = ans[i-1] + 1;
            for(int k=i-1; k>=1; --k) { //
                if(dp[k][i]) {
                    ans[i] = min(ans[k-1] + 1, ans[i]);
                }
            }
        }


        return ans[len-1];
    }
};

int main(int argc, char const *argv[])
{
    string s1;
    cin >> s1;

    Solution sol;

    int ans = sol.minCut(s1);

    cout << ans << endl;
    return 0;
}