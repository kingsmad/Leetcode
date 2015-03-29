#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
        int slen = S.size();
        int tlen = T.size();
        int dp[slen+1][tlen+1];
        dp[0][0] = 1;
		for(int i=1; i<tlen+1; ++i)
			dp[0][i] = 0;
		for(int i=1; i<slen+1; ++i)
			dp[i][0] = 1;
        for(int i=1; i<slen+1; ++i) {
            for(int k=1; k<tlen+1; ++k) {
                if(k>i)
                    dp[i][k] = 0;
                else if(S[i-1] == T[k-1]) {
                    dp[i][k] = dp[i-1][k-1] + dp[i-1][k];
                }
                else {
                    dp[i][k] = dp[i-1][k];
                }
            }
        }
        
        return dp[slen][tlen];
    }
};


int main(int argc, char** argv) {
	string s1, s2;
	cin >> s1 >> s2;

	Solution sol;
	int ans = sol.numDistinct(s1, s2);


	printf("\nThe ans is: %d\n", ans);

	return 0;

}
