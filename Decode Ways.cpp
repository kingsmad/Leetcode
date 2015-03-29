#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solutioon instance will be reused for each test case.
        int len = s.size();
        if(len < 1)
            return 0;
        vector<int> dp(len+1, 0);
        
        if(s[len-1] != '0')
            dp[len-1] = 1;
        dp[len] = 1;
        
        for(ssize_t i=len-2; i>=0; --i) {
            if(s[i] == '0')
                continue;
            dp[i] += dp[i+1];
            if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))
                dp[i] += dp[i+2];
        }
        
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    while(true) {
        string s1;
        cin >> s1;

        Solution s;
        int c = s.numDecodings(s1);

        cout << "num is: " << c << endl;
    }
    return 0;
}