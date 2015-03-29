#include <map>
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len < 2) {
        	return len;
        }

        map<char, int> smap;
        int first = 0;
        int ans = 0; int cnt = 0;

        for(int i=0; i<len; ++i) {
        	map<char, int>::iterator it = smap.find(s[i]);
        	if(it == smap.end()) {
        		smap.insert(make_pair(s[i], i));
        		if(++cnt > ans)
        			ans = cnt;
        	}
        	else {
        		int index = it->second;
        		for(int k=first; k<index; ++k)
        			smap.erase(s[k]); 
        		first = index + 1;
        		cnt = i - index;
        		it->second = i;
        	}
        }

        return ans;
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	string s;
	cin >> s;

	Solution sol;
	int ans = sol.lengthOfLongestSubstring(s);

	cout << "ans is :" << ans << endl;

	return 0;
}