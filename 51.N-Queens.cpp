/*************************************************************************
    > File Name: 51.N-Queens.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Tue Apr  7 10:38:56 2015
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<int> pos;

        __dfs(n, pos, ans);
        
        return ans;
    }

    void __dfs(int n, vector<int>& pos, vector<vector<string> >& ans) {
        int lrow = pos.size();
        if(lrow == n) {
            vector<string> board(n, string(n, '.'));
            for(int i=0; i<n; ++i) {
                board[i][pos[i]] = 'Q';
            }
            ans.push_back(board);
            return;
        }

        for(int i=0; i<n; ++i) {
            bool ok = true;
            for(int j=0; j<lrow; ++j) {
                if(pos[j] == i || pos[j]-j==i-lrow \
                        || pos[j]+j==i+lrow) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                pos.push_back(i);
                __dfs(n, pos, ans);
                pos.pop_back();
            }
        }
        return;
    }
};
/*
Former solution use ps instead of sizeof pos to indicate current depth,
which may be better for semantic understanding
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
};*/
int main(int argc, char** argv ) {
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
