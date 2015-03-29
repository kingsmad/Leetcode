#include <iostream>
using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!A || n < 1)
        	return -1;

        int left = 0;
        int right = n-1;

        while(left < right) {
        	int pos = (left + right ) >> 1;
        	if (A[pos] < A[n-1])
        		right = pos;
        	else 
        		left = pos + 1;
        }
        /*上面代码中，17行不用pos-1，因为left和right的中位数取的是靠近left的那一个，
        	所以pos是不可能等于right而引起问题的*/
        /* but "left" must use pos+1, because the pos may be equal to left. 
        	the loop ends when left meets right: (right is always in the right side)
        		then , "be" is equal to left when they meets*/
        int be = left;
        int len = n;
        int half = len;

        while(len > 0) {
        	half = len >> 1;
        	if(A[(be + half)%n] < target){
        		be = (be + half)%n + 1;
        		len = len - half - 1;
        	}
        	else if(A[(be+half)%n] == target)
        		return (be+half)%n;
        	else 
        		len = half;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
	// int A[2] = {3,1};
	// int A[3] = {1,3,5};
	// int A[3] = {5,1,3};
	int A[1] = {1};
	Solution s;
	cout << s.search(A, 1, 0) << endl;
	return 0;
}