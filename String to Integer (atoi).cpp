#include <iostream>

using namespace std;
class Solution {
public:
    int atoi(const char *str) {
        long ans = 0;
        bool ispositive = true;
        bool find_positive = false;
        
        for(; *str; ++str) {
            if(*str == ' ')
                continue;
            if(!find_positive) {
                if(*str == '+' || *str == '-') {
                    ispositive = (*str == '+');
                    find_positive = true;
                    continue;
                }
            }
            if(isdigit(*str)) {
                ans = ans * 10 + *str - '0';
            }
            else
                break;
        }
        if(!ispositive)
            ans = -ans;
        if(ans > INT_MAX)
            return INT_MAX;
        if(ans < INT_MIN)
            return INT_MIN;
        
        return (int)ans;
    }
};

int main(int argc, char const *argv[])
{
    string s1;
    cin >> s1;
    Solution sol;
    int ans = sol.atoi(s1.c_str());
    cout << ans << endl;
    return 0;
}