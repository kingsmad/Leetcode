#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
	int row = dungeon.size();
	if(row < 1)
	    return 0;
	int col = dungeon[0].size();
	
	int dp[row][col];
	
	for(int i=row-1; i>=0; --i) {
	    for(int j=col-1; j>=0; --j) {
		if(i+1 == row && j+1 == col) {
		    dp[i][j] = max(1, 1 - dungeon[i][j]);
		    continue;
		}
		int t = INT_MAX;
		if(j+1 < col)
		    t = min(t, dp[i][j+1] - dungeon[i][j]); 
		if(i+1 < row) 
		    t = min(t, dp[i+1][j] - dungeon[i][j]);
		t = max(t, 1);
		dp[i][j] = t;
	    }
	}

	return dp[0][0];
    }

};

int main(int argc, char** argv) {

}
