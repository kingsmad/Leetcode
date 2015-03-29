#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int vlen = strs.size();
        if(vlen == 0)
        	return "";
        else if(vlen == 1)
        	return strs[0];
        int pv = 0;
        bool on_busy = true;

        while(on_busy) {
            for(int i=0; i<vlen; ++i) {
            	if(pv >= strs[i].size() || strs[i][pv] != strs[0][pv]) {
            		on_busy = false;
            		break;
            	}
            }
            if(on_busy)
            	++pv;
        }

        return strs[0].substr(0, pv);
    }
};

int main(int argc, char const *argv[])
{
	int len;
	cin >> len;

	vector<string> strs(len);

	for(int i=0; i<len; ++i)
		cin >> strs[i];

	Solution sol;
	string ans = sol.longestCommonPrefix(strs);

	cout << "ans is : " << ans << endl;
	return 0;
}