#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<vector<string> > partition(string s) {
    	ans.clear();
    	vector<string> strs;

    	__Dfs(0, strs, s);

    	return ans;
    }

    void __Dfs(int pos, vector<string>& strs, string& s) {
    	if(pos == s.size()) {
    		ans.push_back(strs);
    		return ;
    	}
    	for(int i=pos; i<s.size(); ++i) {
    		int p = i;
    		int q = pos;

    		bool ok = true;
    		while(p >= q ) {
    			if(s[p] != s[q]) {
    				ok = false;
    				break;
    			}
    			--p;
    			++q;
    		}
    		if(ok) {
    			strs.push_back(s.substr(pos, i-pos+1));
    			__Dfs(i+1, strs, s);
    			strs.pop_back();
    		}
    	}
    }

private:
	vector<vector<string> > ans;
};

int main(int argc, char const *argv[])
{
	/* code */
	string s1;
	cin >> s1;

	Solution sol;
	vector<vector<string> > ans = sol.partition(s1);

	for(int i=0; i<ans.size(); ++i) {
		for(int k=0; k<ans[i].size(); ++k) {
			cout << ans[i][k] << " ";
		}
		cout << endl;
	}
	return 0;
}