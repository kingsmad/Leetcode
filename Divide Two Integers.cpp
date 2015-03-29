#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(divisor == 0 || dividend == 0)
            return 0;

        uint32_t a = abs(dividend);
        uint32_t b = abs(divisor);
        if(a < b)
            return 0;

        int cnt = 0;
        while(a >= b) 
        {
            uint64_t t = b;
            uint64_t p = 1;
            while(t << 1 <= a) {
                t = t << 1;
                p = p << 1;
            }
            a -= t;
            cnt += p;
        }
        if((dividend < 0 && divisor) || (dividend > 0 && divisor > 0)){
            return cnt;
        }

        else 
            return -cnt;
    }
};


int main(int argc, char const *argv[])
{
    int n;
    int t;
    cin >> n;
    cin >> t;
    
    Solution s;
    cout << s.divide(n, t) << endl;
    return 0;
}