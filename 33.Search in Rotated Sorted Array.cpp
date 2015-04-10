/*************************************************************************
    > File Name: 33.Search in Rotated Sorted Array.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  9 16:03:31 2015
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int first = __findFirst(A, n);
        int len = n;
        while(len > 0) {
            int half = len >> 1;
            int pos = (first + half) % n;
            if(A[pos] > target) {
                len = half;
            } else if(A[pos] < target) {
                first = first + half + 1;
                len = len - half - 1;
            } else 
                return pos;
        }

        return -1;
    }

    int __findFirst(int* A, int n) {
        if(n < 2)
            return 0;
        int* first = A;
        while(first < A+n && *first == A[n-1])
            ++first;
        int* last = A + n;
        
        while(first < last && *first > *(last-1)) {
            int* half = first + (last - first - 1) / 2;
            if(*half < *first) {
                last = half + 1;
            } else {
                first = half + 1;
            } 
        }

        return first - A;
    }
};

int main(int argc, char** argv) {
    int opt = 0;
    bool check_first = false;
    while((opt = getopt(argc, argv, "f")) != -1) {
        switch (opt) {
            case 'f':
               check_first = true; 
               break;
            default:
               break;
        }
    }

    fstream in("/Users/Archer/Desktop/dat.txt");
    cin.rdbuf(in.rdbuf());
    int len;
    cin >> len;
    int A[len];
    for(int i=0; i<len; ++i)
        cin >> A[i];

    Solution sol;
    int ans, target;

    if(check_first) {
        ans = sol.__findFirst(A, len);
    } else {
        printf("Please enter target:\n");
        cin >> target;
        ans = sol.search(A, len, target); 
    }

    cout << ans << endl;
}

