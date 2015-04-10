/*************************************************************************
  > File Name: 44.Wildcard Matching.cpp
  > Author: Archer Liu
  > Mail: maple.km2041@me.com 
  > Created Time: Tue Apr  7 16:27:35 2015
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

bool isMatch(const char *s, const char *p) {  
    bool star = false;  
    const char *str, *ptr;  
    for(str = s, ptr =p; *str!='\0'; str++, ptr++)  
    {  
        switch(*ptr)  
        {  
            case '?':  
                break;  
            case '*':  
                star =true;  
                s=str, p =ptr;  
                while(*p=='*')  
                    p++;  
                if(*p == '\0') // 如果'*'之后，pat是空的，直接返回true  
                    return true;  
                str = s-1;  
                ptr = p-1;  
                break;  
            default:  
                {  
                    if(*str != *ptr)  
                    {  
                        // 如果前面没有'*'，则匹配不成功  
                        if(!star)  
                            return false;  
                        s++;  
                        str = s-1;  
                        ptr = p-1;  
                    }  
                }  
        }  
    }  
    while(*ptr== '*')  
        ptr++;  
    return (*ptr == '\0');  
} 

/*class Solution {
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
};*/
    
int main(int argc, char** argv) {
    char buf1[200];
    char buf2[200];

    scanf("\n%s", buf1);
    scanf("\n%s", buf2);

    Solution sol;
    bool done = sol.isMatch(buf1, buf2);
    if(done)
        cout << "Done!\n";
    else
        cout << "Failed!\n";
    return 0;
}
