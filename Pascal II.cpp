#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        ans.push_back(vector<int>(1, 1));
        
        --numRows;
        while(numRows--) {
            vector<int>& pre = ans.back();
            vector<int> tv;
            
            tv.push_back(1);
            for(int i=0; i+1<pre.size(); ++i) {
                tv.push_back(pre[i] + pre[i+1]);
            }
            tv.push_back(1);
            
            ans.push_back(tv);
        }
        
        return ans;
    }
};


int main(int argc, char** argv) {
    int numRows;
    cin >> numRows;

    Solution sol;
    vector<vector<int> > ans = sol.generate(numRows);

    for(int i=0; i<ans.size(); ++i) {
        for(int j=0; j<ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}