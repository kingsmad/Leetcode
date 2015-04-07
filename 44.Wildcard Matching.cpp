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
