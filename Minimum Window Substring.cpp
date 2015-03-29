#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if(S.length() < T.length()){
            return "";
        }
        
        int base[128];
        memset(base, 0, sizeof(base));
        
        for(int i=0; i<T.length(); i++){
            base[T[i]] --;
        }
        int total = -T.length();
        int first = 0;
        int last = 0;
        int ans_start = 0, ans_end = S.length()+1;
        for(;;){
            while(total<0 && last<S.length()){
                if(base[S[last]] < 0){
                    total++;
                }
                base[S[last]] ++;
                last++;
            }
            if(total < 0){
                break;
            }
            while(base[S[first]] > 0){
                base[S[first]]--;
                first++;
            }
            if((last-first) < (ans_end-ans_start)){
                ans_end = last;
                ans_start = first;
            }
            base[S[first]]--;
            first++;
            total--;
        }
        if(ans_end == (S.length()+1)){
            return "";
        }else{
            return S.substr(ans_start, (ans_end-ans_start));
        }
    }
};


int main(int argc, char** argv) {
	string s1;
	string s2;
	cin >> s1 >> s2;

	printf("\ns1 and s2 are:");
	cout << s1 << s2;

	Solution sol;
	string ans = sol.minWindow(s1, s2);

	cout << "The ans is: " << ans;

	return 0;
}
