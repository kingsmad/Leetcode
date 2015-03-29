#include <algorithm>

#include <iostream>
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        for(int i=0; i<n; ++i) {
            while(A[i] >= 1 && A[i] < n+1 && A[i] != i+1) {
                if(A[A[i]-1] == A[i])
                    break;
                else {
                    int tmp = A[A[i]-1];
                    A[A[i]-1] = A[i];
                    A[i] = tmp;
                }
            }
        }

        int pos = 0;
        for(; pos<n; ++pos) {
            if(A[pos] != pos+1)
                break;
        }
        return pos+1;
    }
};
int main(int argc, char* argv[]) {
	int A[10] = {1,1};
	Solution s;
	std::cout << s.firstMissingPositive(A,10) << std::endl;
}