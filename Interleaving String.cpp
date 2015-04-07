/*************************************************************************
    > File Name: Interleaving String.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  2 23:42:59 2015
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
	int len1 = s1.size();
	int len2 = s2.size();
	int len3 = s3.size();
	if(len1 + len2 != len3)
	    return false;

	vector<vector<bool> > dp(len1+1, vector<bool>(len2+1, false));
	dp[0][0] = true;
	for(int i=0; i<len1+1; ++i) {
	    for(int j=0; j<len2+1; ++j) {
		if(i > 0 && s1[i-1] == s3[i+j-1] && dp[i-1][j])
		    dp[i][j] = true;
		if(j > 0 && s2[j-1] == s3[i+j-1] && dp[i][j-1])
		    dp[i][j] = true;
	    }
	}
	
	return dp[len1][len2];	
    }
};

int main(int argc, char** argv) {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    Solution sol;
    bool done = sol.isInterleave(s1, s2, s3);

    if(done)
	cout << "done!\n";
    else
	cout << "failed\n";
}
