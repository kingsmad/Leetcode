/*************************************************************************
    > File Name: 45.Jump Game II.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Tue Apr  7 10:11:22 2015
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        if(!A)
            return 0;
        int last = 1;
        int pos = 0;
        int dep = 0;
        
        while(last < n) {
            int clast = last;
            for(int i=pos; i<last; ++i ) {
                clast = max(clast, A[i] + i + 1);
            }
            pos = last;
            last = clast;
            ++dep;
        }

        return dep; 
    }
};

int main(int argc, char** argv ) {
    int len ;
    cin >> len;
    int A[len];
    for(int i=0; i<len; ++i) 
        cin >> A[i];

    Solution sol;
    int ans = sol.jump(A, len);
    cout << "The answer is: " << ans << endl;

    return 0;
}
