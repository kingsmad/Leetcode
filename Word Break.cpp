class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.size();

        vector<bool> dp(len+1, false); //dp代表到第i个位置为止，不包括第i个位置。
        dp[0] = true;
        /*初始化,取值范围dp为0到len*/
        for(ssize_t i=1; i<=len; ++i)
        	if(dict.count(s.substr(0, i)) > 0)
        		dp[i] = true;
        	

        for(ssize_t i=0; i<len+1; ++i) {
        	if(dp[i]) {
        		for(ssize_t k=i+1; k<len+1; ++k) {
        			if(dict.count(s.substr(i, k-i)) > 0)
        				dp[k] = true;
        		}
        	}
        }

        return dp[len];
    }
};