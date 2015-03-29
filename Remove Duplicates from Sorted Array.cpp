#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(A == NULL || n < 2)
            return n;
        int cur = A[0];
        int last = 0;
        
        for(int p = 1; p<n; ++p) {
            if(A[p] != cur) {
                cur = A[p];
                A[++last] = A[p];
            }
        }
        
        return last + 1;
    }
};


int main(int argc, char const *argv[])
{
    int len;
    cin >> len;

    int num[len];
    for(int i=0; i<len; ++i)
        cin >> num[i];

    Solution s;
    int ans = s.removeDuplicates(num, len);

    for(int i=0; i<len-1; ++i) {
        cout << num[i] << " ";
    }
    cout << num[len-1] << endl;

    cout << "the final num length is : " << ans << endl;
    return 0;
}