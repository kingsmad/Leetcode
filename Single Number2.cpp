class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ones = 0; int twos = 0;
        for(int pi=0; pi<n; ++pi){
        	int temp = ones;
        	ones ^= A[pi];	//add the num for 1
        	ones &= ~twos;	//delete the fake 1 from which the bit is actually 2
            twos = (temp & A[pi]) | (twos & (~A[pi]));
            /* twos comes from two parts: the ones add 1; and the original twos that
				has npt been eliminate by A[pi]*/
        }
        return ones | twos;
    }
};