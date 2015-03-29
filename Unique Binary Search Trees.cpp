#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n < 0)
            return -1;
        vector<int> num(n+1, 0);
        num[0] = 1;
        num[1] = 1;
        num[2] = 2;
        
        for(int i=3; i<n+1; ++i) {
            int tmp = 0;
            for(int p=1; p<=i; ++p) {
                tmp += num[p-1] * num[i-p];
            }
            num[i] = tmp;
        }
        
        return num[n];
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    Solution s;
    cout << "numTrees is : " << s.numTrees(n) << endl;
    return 0;
}