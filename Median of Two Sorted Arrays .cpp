#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int index = (m+n) >> 1;
        if((m+n) & 1) {
            ++index;
            return __FindKth(A, m, B, n, index);
        }
        else {
            return (__FindKth(A, m, B, n, index+1) + __FindKth(A, m, B, n, index)) / 2.0;
        }
    }
    
    double __FindKth(int* A, int m, int* B, int n, int k) {
        if(m < n)
            return __FindKth(B, n, A, m, k);
        if(n == 0) {
            return A[k-1];
        }
        
        int half = m >> 1;
        int* t = lower_bound(B, B+n, A[half]);
        int less_len = half + t - B + 1;
        
        if(less_len < k) {
            return __FindKth(A+half+1, m-half-1, t, B+n-t, k-less_len);
        }
        else if (less_len == k)
            return A[half];
        else {
            return __FindKth(A, half, B, t-B, k);
        }
    }
};


int main(int argc, char const *argv[])
{
    int alen ;
    int blen;
    cin >> alen;
    cin >> blen;

    int A[alen];
    int B[blen];
    for(int i=0; i<alen; ++i)
        cin >> A[i];
    for(int i=0; i<blen; ++i)
        cin >> B[i];

    Solution s;
    double t = s.findMedianSortedArrays(A, alen, B, blen);

    cout << t << endl;
    return 0;
}