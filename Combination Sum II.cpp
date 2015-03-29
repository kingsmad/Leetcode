#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        ans_.clear();
        path_.clear();

        sort(num.begin(), num.end());
        __Dfs(0, 0, num, target);
        
        return ans_;
    }
    
    void __Dfs(int pos, int sum, vector<int>& num, int target) {
        if(sum > target)
            return; 
        if(sum == target) {
            ans_.push_back(path_);
            return;
        }

        for(int i=pos; i<num.size(); ++i) {
            bool ok = true;
            for(int k=pos; k<i; ++k)
                if(num[k] == num[i])
                    ok = false;
            if(!ok)
                continue;
            path_.push_back(num[i]);
            __Dfs(i+1, sum+num[i], num, target);
            path_.pop_back();
        }
    }
private:
    vector<vector<int> > ans_;
    vector<int> path_;
};

int main(int argc, char const *argv[])
{
    int len, target;
    cin >> len;
    cin >> target;
    vector<int> vec(len);
    for(int i=0; i<len; ++i) {
        cin >> vec[i];
    }

    Solution sol;
    vector<vector<int> > ans = sol.combinationSum2(vec, target);

    for(int i=0; i<ans.size(); ++i) {
        for(int k=0; k<ans[i].size(); ++k) {
            cout << ans[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}