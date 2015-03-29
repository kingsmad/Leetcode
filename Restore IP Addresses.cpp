#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct dfs_status {
	int stage;
	int last;
	int path[4];
};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	ans_.clear();
    	path_.clear();
    	struct dfs_status sta;
    	memset(&sta, 0, sizeof(sta));

    	__Dfs(sta, s);

    	return ans_;
    }
    void __Dfs(struct dfs_status& sta, string& s) {
    	if(sta.stage == 4 && sta.last == s.size()) {
    		__AddRes(sta, s);
    		return ;
    	}
    	if(sta.stage == 4 || sta.last == s.size()) {
    		return;
    	}

    	for(int i=1; i<4; ++i) {
    		if(__isValid(sta.last, i, s)) {
    			struct dfs_status tmp = sta;
    			tmp.stage = sta.stage + 1;
    			tmp.last = sta.last + i;
    			tmp.path[tmp.stage] = i;

    			__Dfs(tmp, s);
    		}
    	}
    }

    bool __isValid(int first, int len, string& s) {
    	if(first + len > s.size())
    		return false;
    	if(len == 1)
    		return true;
    	if(s[first] == '0')
    		return false;
    	int sum = 0;
    	while(len--) {
    		sum += sum*10 + (s[first]-'0');
    		++first;
    	}
    	if(sum <= 255)
    		return true;
    	return false;
    }

    void __AddRes(dfs_status& sta, string& s) {
    	vector<char> tmp;
    	int stage = 0;
    	for(int i=0; i<s.size(); ) {
    		if(!tmp.empty())
    			tmp.push_back('.');
    		int cnt = sta.path[stage];
    		while(cnt--) {
    			tmp.push_back(s[i]);
    			++i;
    		}
    		++stage;
    	}

    	ans_.push_back(string(tmp.begin(), tmp.end()));
    }
private:
	vector<string> ans_;
	vector<int> path_;
};

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	Solution sol;
	vector<string> ans = sol.restoreIpAddresses(str);

	for(int i=0; i<ans.size(); ++i) 
		cout << ans[i] << endl;

	cout << ans.size() << endl;
	return 0;
}