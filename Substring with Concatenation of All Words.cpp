#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int word_size = L[0].size();
        int len = L.size() / word_size;
        for(int b=0; b<word_size; ++b) {
            for(int i=b; i+L.size()<S.size(); i+=word_size) {
                bool ok = true;
                unordered_map<string, int> imap;
                for(auto str : L) 
                    imap[str] += 1;
                    
                for(int k=0; k<len; ++k) {
                    auto it = imap.find(S.substr(i+k*word_size, word_size));
                    if(--it->second < 0) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};

int main(int argc, char** argv) {
	string S;
	cin >> S;
	int len;
	cin >> len;
	
	vector<string> L(len);
	for(int i=0; i<len; ++i) {
		cin >> L[i];
	}
	
	Solution sol;
	vector<int> res = sol.findSubstring(S, L);

	for(auto c : res) 
		printf("%d ",c);
	printf("\n");
}
