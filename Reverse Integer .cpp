#include <iostream>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        bool negative = false;
        if(x < 0) {
            negative = true;
            x = -x;
        }
        
        char num[20];
        memset(num, 0, sizeof(num));
        sprintf(num, "%d", x);
        
        int last = 0;
        int first = 0;
        while(num[last] != 0)
            ++last;
        --last;
        for(; first<last; ++first, --last) {
            iter_swap(num+first, num+last);
        }
        
        int ans = 0;
        sscanf(num, "%d", &ans);
        
        ans = negative ? -ans : ans;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    Solution s;
    cout << "after convertion is : " << s.reverse(x) << endl;
    return 0;
}