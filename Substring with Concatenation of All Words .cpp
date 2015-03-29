#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;


class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;

        if(S.size() == 0)
        	return ans;
        
        int str_siz = L[0].size();
        
        unordered_map<string, int> str_map;
        for(int i=0; i<L.size(); ++i)
        	++str_map[L[i]];

        for(int offset=0; offset<str_siz; ++offset) {
        	int left = offset;
        	int cnt = 0;
        	for(int pv=left; pv+str_siz<=S.size(); pv+=str_siz) {
        		auto it = str_map.find(S.substr(pv, str_siz));
        		if(it == str_map.end()) {
        			while(left < pv) {
        				++str_map[S.substr(left, str_siz)];
        				left += str_siz;
        			}
        			left = pv + str_siz;
        			cnt = 0;
        		}
        		else {
        			++cnt;
        			if(--it->second < 0) {
        				for(; left<pv; ) {
        					auto c = str_map.find(S.substr(left, str_siz));
        					++c->second;
        					--cnt;
        					left += str_siz;
        					if(c == it)
        						break;
        				}
        			}
        			else {
        				if(cnt == L.size()) {
        					ans.push_back(left);
                            
        					++str_map[S.substr(left, str_siz)];
        					left += str_siz;
        					--cnt;
        				}
                        
        			}
        		}
        	}
            while(left+str_siz < S.size()) {
                ++str_map[S.substr(left, str_siz)];
                left += str_siz;
            }
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
	fstream in("/Developer/dat.txt");
	cin.rdbuf(in.rdbuf());
	
	int len;
	cin >> len;

	vector<string> L(len);
	for(int i=0; i<len; ++i) 
		cin >> L[i];

	string S;
	cin >> S;

	Solution sol;
	vector<int> ans = sol.findSubstring(S, L);

	for(int i=0; i<ans.size(); ++i)
		cout << ans[i] << " ";

	cout << endl;
	return 0;
}