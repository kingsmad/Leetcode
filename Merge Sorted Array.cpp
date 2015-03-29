#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(B == NULL || A==NULL)
            return;
        
        vector<int> num(m+n, 0);
        int pi = 0;
        int pv = 0;
        int des = 0;
        
        while(pi < m && pv < n) {
            if(A[pi] < B[pv]) {
                num[des++] = A[pi];
                ++pi;
            }
            else {
                num[des++] = B[pv];
                ++pv;
            }
        }
        
        while(pi < m) {
            num[des++] = A[pi++];
        }
        while(pv < n) {
            num[des++] = B[pv++];
        }
        
        for(int k=0; k<m+n; ++k) {
            A[k] = num[k];
        }
    }
};


int main(int argc, char const *argv[])
{
    const int MAXLEN = 100;
    int* A = (int*)malloc(MAXLEN * sizeof(int));
    
    int lenA;
    cin >> lenA;
    int lenB;
    cin >> lenB;
    
    int* B = (int*)malloc(lenB * sizeof(int));
    for(int i=0; i<lenA; ++i) {
        cin >> A[i];
    }
    
    for(int i=0; i<lenB; ++i)
        cin >> B[i];
    
    Solution s;
    s.merge(A, lenA, B, lenB);
    for(int i=0; i<lenA+lenB-1; ++i) {
        cout << A[i] << " " ;
    }
    cout << A[lenA+lenB-1] << endl;
    free(A);
    
    return 0;
}