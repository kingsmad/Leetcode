#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       	vector<string> ans;
       	if(strs.empty())
       		return ans;

       	map<string, vector<int> > map;
       	for(int i=0; i<strs.size(); ++i) {
       		string tmp = strs[i];
       		sort(tmp.begin(), tmp.end());

       		map[tmp].push_back(i);
       	}
       	auto it = map.begin();
       	for(; it!=map.end(); ++it) {
       		if(it->second.size() > 1)
       			break;
       	}
       	if(it == map.end())
       		--it;
       	vector<int>& vec = it->second;
       	for(int i=0; i<vec.size(); ++i) {
       		ans.push_back(strs[vec[i]]);
       	}

       	return ans;
    }
};



int main(int argc, char const *argv[])
{
	int len;
	cin >> len;
	vector<string> strs(len);

	for(int i=0; i<len; ++i) {
		cin >> strs[i];
	}
	Solution sol;
	vector<string> ans = sol.anagrams(strs);

	for(int i=0; i<ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}