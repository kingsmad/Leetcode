#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> pos(n, 0);
        __Dfs(0, pos, n, ans);

        return ans;
    }

    void __Dfs(int ps, vector<int>& pos, int n, int& ans) {
    	if(ps == n) {
    		++ans;
    		return ;
    	}

    	for(int i=0; i<n; ++i) {
    		bool ok = true;
    		for(int k=0; k<ps; ++k) {
    			if(pos[k] == i || k-pos[k] == ps-i || k+pos[k] == ps+i) {
    				ok = false;
    				break;
    			}
    		}
    		if(ok) {
    			pos[ps] = i;
    			__Dfs(ps+1, pos, n, ans);
    		}
    	}
    }
};

int main(int argc, char const *argv[])
{
	int n ;
	cin >> n;
	Solution sol;
	n = sol.totalNQueens(n);
	cout << "res is : " << n << endl;
	return 0;
}