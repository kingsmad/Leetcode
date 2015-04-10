/*************************************************************************
    > File Name: 4.Median of Two Sorted Arrays.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Wed Apr  8 00:50:39 2015
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int t = findKthNum(A, m, B, n, (m+n+1)/2);
        if((m+n) & 1)
            return t;
        t += findKthNum(A, m, B, n, (m+n)/2);
        return t / 2.0;
    }

    int findKthNum(int* A, int m, int* B, int n, int k) {
        if(m < n)
            return findKthNum(B, n, A, m, k);
        if(n == 0)
            return A[k-1];
        if(k == 1)
            return min(A[0], B[0]);
        int pb = min(n, k/2);
        int pa = k - pb;
        if(A[pa-1] > B[pb-1])
            return findKthNum(A, m, B+pb, n-pb, k-pb);
        else if(A[pa-1] < B[pb-1])
            return findKthNum(A+pa, m-pa, B, pb, k-pa);
        else
            return A[pa-1];
    }
};

bool test_kth = false;
int kth = 0;
int main(int argc, char** argv ) {
    int opt = 0;
    while((opt = getopt(argc, argv, "k:")) != -1) {
        switch (opt) {
            case 'k':
                test_kth = true;
                kth = atoi(optarg);
                break;
            default:
                break;
        }
    }

    fstream in("/Users/Archer/Desktop/dat.txt");
    cin.rdbuf(in.rdbuf());
    int m, n;
    cin >> m >> n;

    int A[m], B[n];
    for(int i=0; i<m; ++i ) 
        cin >> A[i];
    for(int i=0; i<n; ++i )
        cin >> B[i];

    Solution sol;
    if( test_kth) {
        int ans = sol.findKthNum(A, m, B, n, kth);
        printf("The %dth num is: %d", kth, ans);
    }
    else {
        int ans = sol.findMedianSortedArrays(A, m, B, n);
        printf("The answer is: %d", ans);
    }

    return 0;
}
