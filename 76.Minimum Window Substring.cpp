/*************************************************************************
    > File Name: 76.Minimum Window Substring.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Mon Apr  6 13:46:13 2015
 ************************************************************************/

#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
private:
    int buf1[256];
    int buf2[256];
public:
    string minWindow(string S, string T) {
        int len1 = S.size();
        int len2 = T.size();
        memset(buf1, 0, sizeof(buf1));
        memset(buf2, 0, sizeof(buf2));
        if(len1 < 1 || len2 < 1 || len1 < len2)
            return "";
        
        for(int i=0; i<len2; ++i) {
            buf2[T[i]] += 1;
        }
        
        int first = 0;
        int min_first = 0;
        int min_len = INT_MAX;
        int cnt = 0;
        for(int i=0; i<len1; ++i) {
            ++buf1[S[i]];
            if(buf1[S[i]] <= buf2[S[i]]) 
                ++cnt;
            while(first<i && buf1[S[first]] > buf2[S[first]]) {
                buf1[S[first]] -= 1;
                ++first;
            }
            if(cnt == len2 && min_len > i-first+1) {
                min_first = first;
                min_len = i - first + 1;
            }
        }

        if(min_len == INT_MAX)
            return "";
        return S.substr(min_first, min_len); 
    }
};

int main(int argc, char** argv ) {
    string s1, s2;
    cin >> s1 >> s2;

    Solution sol;
    string ans = sol.minWindow(s1, s2);

    cout << "The answer is: " << ans << endl;
}
