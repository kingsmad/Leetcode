#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        ans_.clear();
        vector<int> pos(n, 0);
        
        	__Dfs(0, pos, n);
        return ans_;
    	
    }

    void __Dfs(int ps, vector<int>& pos, int n) {
    	if(ps == n) {
    		vector<string> tmp;
    		string dot(n, '.');
    		for(int i=0; i<n; ++i) {
    			tmp.push_back(dot);
    			tmp[i][pos[i]] = 'Q';
    		}
    		ans_.push_back(tmp);
    	}
    	else {
    		for(int k=0; k<n; ++k) {
    			/*检查是否k能够正确*/
    			bool ok = true;
    			for(int j=0; j<ps; ++j) {
    				if(pos[j] == k || j - pos[j] == ps - k
    					 || j+pos[j] == ps+k) {
    					ok = false;
    					break;
    				}
    			}
    			if(ok) {
    				pos[ps] = k;
    				__Dfs(ps+1, pos, n);
    			}
    		}
    	}
    }
private:
	vector<vector<string> > ans_;
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Solution sol;
	vector<vector<string> > strs = sol.solveNQueens(n);
	for(int i=0; i<strs.size(); ++i) {
		for(int j=0; j<strs[i].size(); ++j) 
			cout << strs[i][j] << endl;
		cout << endl;
	}

	return 0;
}