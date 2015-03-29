#include <iostream>
#include <string>
#include <vector>


using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
    	int cnt = 0;
    	if(nRows == 1)
    		return s;
    	bool dict = false;
    	vector<vector<char> > pool(nRows);
    	for(int i=0; i<s.size(); ++i) {
    		pool[cnt].push_back(s[i]);
    		
    		if(cnt == 0 || cnt == nRows-1)
    			dict = !dict;
    		if(dict)
    			++cnt;
    		else
    			--cnt;
    	}

    	vector<char> ans;
    	for(int i=0; i<pool.size(); ++i) {
    		for(int k=0; k<pool[i].size(); ++k)
    			ans.push_back(pool[i][k]);
    	}

    	return string(ans.begin(), ans.end());
    }
};

int main(int argc, char const *argv[])
{
	string s1;
	int len;
	cin >> s1;
	cin >> len;

	Solution sol;
	string ans = sol.convert(s1, len);

	cout << ans << endl;
	return 0;
}