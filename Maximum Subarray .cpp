#include <iostream>

using namespace std;
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(A == NULL || n < 1)
            return 0;
        int ans = 0;
        int curSum = 0;
        
        for(int pv=0; pv<n; ++pv) {
            curSum += A[pv];
            if(curSum > ans) {
                ans = curSum;
            }
            else if(curSum < 0) {
                curSum = 0;
            }
        }
        
        if(ans == 0) {
            ans = A[0];
            for(int i=0; i<n; ++i) {
                if(ans < A[i])
                    ans = A[i];
            } 
        }
        return ans;
    }
};



int main(int argc, char const *argv[])
{
    int len;
    cin >> len;

    int A[len];
    for(int i=0; i<len; ++i)
        cin >> A[i];

    Solution s;
    cout << "maximum maxSubArray is : " << s.maxSubArray(A, len) << endl;
    return 0;
}