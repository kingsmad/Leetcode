/*N[i,j] = N[i-1,j] + if(S[i] == T[j])? N[i-1, j -1]:0;*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int slen = S.size();
        int tlen = T.size();

        int dp[slen+1][tlen+1];
        for(int i=0; i<slen+1; ++i)
        	dp[i][0] = 0;
        for(int i=0; i<tlen+1; ++i)
        	dp[0][i] = 0;

        for(int i=1; i<slen+1; ++i) {
        	for(int j=1; j<i && j<tlen+1; ++j) {
        		dp[i][j] = dp[i-1][j];
        		if(S[i] == T[j]) {
        			if(j == 1)
        				dp[i][j] += 1;
        			else
        				dp[i][j] += dp[i-1][j-1];
        		}
        	}
        }

        return dp[slen][tlen];
    }
};