/*************************************************************************
    > File Name: 47.Permutations II.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  9 13:47:59 2015
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        int len = num.size();
        bool flag[len];
        memset(flag, 0, sizeof(flag));

        vector<vector<int> > ans;
        vector<int> path;

        __dfs(path, flag, num, ans);

        return ans;
    }

    void __dfs(vector<int>& path, bool* flag, vector<int>& num, vector<vector<int> >& ans) {
        int len = num.size();
        if(path.size() == len) {
            ans.push_back(path);
            return;
        }
       
        for(int i=0; i<len; ++i) {
            if(!flag[i] ) {
                flag[i] = true;
                path.push_back(num[i]);

                __dfs(path, flag, num, ans);

                flag[i] = false;
                path.pop_back();

                // Skip same value on same search level            
                while(i+1<len && num[i+1] == num[i])
                    ++i;
            }
        }
    }
};

int main(int argc, char** argv) {
    int len ;
    cin >> len;
    vector<int> num(len, 0);
    for(int i=0; i<len; ++i)
        cin >> num[i];

    Solution sol;
    vector<vector<int> > ans = sol.permuteUnique(num);

    for(int i=0; i<ans.size(); ++i) {
        for(int j=0; j<ans[i].size(); ++j) 
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
