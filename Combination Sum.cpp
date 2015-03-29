#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        ans_.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> num;
       	__Dfs(0, 0, num, candidates, target);

       	return ans_;
    }
    void __Dfs(int cur_sum, int pos, vector<int>& num, vector<int>& candidates, int target) {
    	if(cur_sum > target)
    		return;
    	else if(cur_sum == target) {
    		ans_.push_back(num);
    		return;
    	}
    	for(int i=pos; i<candidates.size(); ++i) {
    		num.push_back(candidates[i]);
    		__Dfs(cur_sum+candidates[i], i, num, candidates, target); //pos只扫描它后面的
    		num.pop_back();
    	}
    }
private:
	vector<vector<int> > ans_;
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
	vector<vector<int> > ans = sol.combinationSum(vec, target);

	for(int i=0; i<ans.size(); ++i) {
		for(int k=0; k<ans[i].size(); ++k) {
			cout << ans[i][k] << " ";
		}
		cout << endl;
	}
	return 0;
}