/*************************************************************************
    > File Name: 52.N-Queens II.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Tue Apr  7 10:37:46 2015
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int ans;
        vector<int> pos(n, 0);
        int ps = 0;
        
        __dfs(ps, pos, n, ans);

        return ans;
    }

    void __dfs(int ps, vector<int>& pos, int n, int& ans) {
        if(ps == n) {
            ++ans;
            return;
        }
        for(int i=0; i<n; ++i) {
            bool ok = true;
            for(int j=0; j<ps; ++j) {
                if(pos[j] == i || pos[j]-j == i-ps \
                        || pos[j]+j == i+ps) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                pos[ps] = i;
                __dfs(ps+1, pos, n, ans);
            }
        }
    }
};

int main(int argc, char** argv ) {
    int len;
    cin >> len;

    Solution sol;
    int ans = sol.totalNQueens(len);

    cout << "The answer is: " << ans << endl;

    return 0;
}
