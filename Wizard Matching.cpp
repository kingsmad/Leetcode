#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        size_t rlen = strlen(p);
        size_t clen = strlen(s);
        
        int dp[2][clen+1];
        int* cur=dp[1];
        int* pre=dp[0];
        memset(cur, 0, sizeof(int)*(clen+1));
        memset(pre, 0, sizeof(int)*(clen+1));
        pre[0] = 1;
        
        for(size_t i=1; i<rlen+1; ++i) {
            for (size_t j=1; j<clen+1; ++j) {
                if( p[i-1] == s[j-1] || p[i-1] == '?') {
                    cur[j] = pre[j-1];
                    continue;
                }
                if (p[i-1] != '*') {
                    cur[j] = 0;
                    continue;
                }
                
                for (int k=j-1; k>=0; --k) {
                    if (cur[k] == 1) {
                        cur[j] = 1;
                        break;
                    }
                }
                if (cur[j] == 0) {
                    for (int k=j; k>=0; --k) {
                        if (pre[k] == 1) {
                            cur[j] = 1;
                            break;
                        }
                    }
                }
                
            }
            int *tmp = cur;
            cur = pre;
            pre = tmp;
        }
        
        return (pre[clen] == 1) ? true : false;
    }
};


int main(int argc, char const *argv[])
{
    string s1;
    string s2;
    
    cin >> s1;
    cin >> s2;
    
    Solution s;
    int f = (s.isMatch(s1.c_str(), s2.c_str())) ? 1 : 0;
    cout << f << endl;
    return 0;
}