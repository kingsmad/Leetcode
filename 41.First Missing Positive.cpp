#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(!A)
            return 1;
        int buf[n];
        memset(buf, 0, sizeof(buf));
        for(int i=0; i<n; ++i) {
            int t = A[i];
            if(t > n || t <= 0)
                continue;
            buf[t-1] = 1;
        }
        
        for(int i=0; i<n; ++i ) {
            if(!buf[i])
                return i + 1;
        }
        
        return n+1;
    }
};

int main(int argc, char** argv) {
    int len;
    cin >> len;
    int buf[len];
    for(int i=0; i<len; ++i)
        cin >> buf[i];

    Solution sol;
    int ans = sol.firstMissingPositive(buf, len);

    cout << ans << endl;
    return 0;
}