#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
class Solution {
public:
	Solution() {
		imap_.insert(make_pair(2, "abc"));
		imap_.insert(make_pair(3, "def"));
		imap_.insert(make_pair(4, "ghi"));
		imap_.insert(make_pair(5, "jkl"));
		imap_.insert(make_pair(6, "mno"));
		imap_.insert(make_pair(7, "pqrs"));
		imap_.insert(make_pair(8, "tuv"));
		imap_.insert(make_pair(9, "wxyz"));
	}
    vector<string> letterCombinations(string digits) {
    	ans_.clear();
    	path_.clear();

    	if(digits.size() < 1) {
    		ans_.push_back("");
    		return ans_;
    	}

    	__Dfs(0, digits);

    	return ans_;
    }

    void __Dfs(int pos, string& s) {
    	if(pos == s.size()) {
    		ans_.push_back(string(path_.begin(), path_.end()));
    		return ;
    	}

    	int str_len = 3;
    	if(s[pos] == '7' || s[pos] == '9')
    		str_len = 4;

    	for(int i=0; i<str_len; ++i) {
    		char c = imap_[s[pos]-'0'][i];
    		path_.push_back(c);
    		__Dfs(pos+1, s);
    		path_.pop_back();
    	}
    	
    }
private:
	vector<string> ans_;
	vector<char> path_;
	map<int, string> imap_;
};

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	Solution sol;
	vector<string> ans = sol.letterCombinations(str);
	for(int i=0; i<ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}