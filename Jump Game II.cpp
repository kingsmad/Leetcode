#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Solution {
public:
    int jump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 1 || A == NULL)
            return 0;
        
        vector<int> depth(n, 0);
        depth[0] = 0;
        int max = 0;

        for(int i=0; i<n; ++i) {
            int tmp = A[i] + i;
            if(tmp > max) {
                if(tmp >= n-1)
                    return depth[i] + 1;
                for(int k=max+1; k<tmp+1; ++k)
                    depth[k] = depth[i] + 1;
                max = tmp;
            }
        }
        
        return depth[n-1];
    }
};


int main(int argc, char const *argv[])
{
    ifstream in("dat.txt");
    cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    int* A = new int[n];
    for(int i=0; i<n; ++i)
        cin >> A[i];

    Solution s;
    cout << "the jump cnt is : " << s.jump(A, n) << endl;

    delete[] A;
    return 0;
}


/*
int jump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int B[n];
        B[0] = 0;
        for(int j=1; j<n; j++){
            B[j] = INT_MAX;
        }
        for(int j=1; j<=A[0]; j++){
            B[j] = 1;
        }

        for(int i=1; i<n; i++){
            for(int j=A[i-1]; j<=A[i]; j++){
                if((i+j) < n){
                    B[i+j] = min(B[i+j], B[i]+1);
                }
            }
        }
        return B[n-1];
    }

*/