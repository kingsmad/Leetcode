#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        ans_.clear();
        tmp_.clear();
        if(S.size() == 0)
            return ans_;

        sort(S.begin(), S.end());
        
        __Dfs(0, S);
        
        return ans_;
    }
    
    void __Dfs(int pos, vector<int>& S) {
        if(pos == S.size()) {
            ans_.push_back(tmp_);
            return;
        }
        if(pos+1 == S.size() || S[pos] != S[pos+1]) {
            __Dfs(pos+1, S);
            tmp_.push_back(S[pos]);
            __Dfs(pos+1, S);
            tmp_.pop_back();
            return;
        }
        
        else {
            int cnt = 0;
            int num = S[pos];
            int first = pos;

            while(pos < S.size() && S[pos] == num)
                ++pos;
            

            for(int i=first; i<=pos; ++i) {
                __Dfs(pos, S);
                tmp_.push_back(num);
            }

            for(int i=first; i<=pos; ++i)
                tmp_.pop_back();
        }


    }
private:
    vector<vector<int> > ans_;
    vector<int> tmp_;
};

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;
    vector<int> S(len);
    for(int i=0; i<len; ++i)
        cin >> S[i];

    Solution sol;
    vector<vector<int> > ans = sol.subsetsWithDup(S);

    for(int i=0; i<ans.size(); ++i) {
        for(int k=0; k<ans[i].size(); ++k) 
            cout << ans[i][k] << " ";
        cout << endl;
    }


    return 0;
}