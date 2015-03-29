#include <iostream>
using namespace std;
class Solution {
public:
    bool search(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!A || n < 1)
        	return -1;

        int left = 0;
        int right = n-1;

        while(A[left] == A[right] && left < right) {
        	++left;
        }

        while(left < right) {
        	int pos = (left + right ) >> 1;
        	if (A[pos] <= A[right])
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
        		return true;
        	else 
        		len = half;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	int A[5] = {3,1,1,1,1};
	Solution s;

	cout << s.search(A, 5, 1) << endl;
	return 0;
}