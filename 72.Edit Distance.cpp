/*************************************************************************
    > File Name: 72.Edit Distance.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Mon Apr  6 16:08:11 2015
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        int dp[len1+1][len2+1];

        for(int i=0; i<len1+1; ++i)
        	dp[i][0] = i;
        for(int i=0; i<len2+1; ++i)
        	dp[0][i] = i;

        for(int i=1; i<len1+1; ++i) {
        	for(int j=1; j<len2+1; ++j) {
        		int m = dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
        		m = min(m, dp[i-1][j] + 1);
        		m = min(m, dp[i][j-1] + 1);
        		dp[i][j] = m;
        	}
        }

        return dp[len1][len2];
    }
};

int main(int argc, char** argv) {
	// string s1, s2;
	// cin >> s1 >> s2;
	string s1 = "";
	string s2 = "";
	Solution sol;
	int ans = sol.minDistance(s1, s2);
	cout << "The answer is: " << ans << endl;

	return 0;
}