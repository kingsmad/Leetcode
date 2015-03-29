#include <iostream>
using namespace std;
class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(x <= 0)
            return 0;
        else if(x == 1)
            return 1;
        double m = x / 2.0;
        for(int i=0; i<10; ++i)
            m = (x / m + m) / 2;
        return m;
    }
};


int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    Solution s;

    cout << s.sqrt(x) << endl;
    return 0;
}