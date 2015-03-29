class Solution {
public:
    bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(A == NULL)
            return false;
        int max = A[0];
        for(int i=0; i<n; ++i) {
            if(i > max)
                return false;
            else if(A[i] + i > max) 
                max = A[i] + i;
        }
        
        return true;
    }
};


/*
 bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n <= 1){
            return true;
        }
        int B[n];
        B[0] = A[0];
        if(B[0] <= 0){
            return false;
        }
        for(int i=1; i<n-1; i++){
            B[i] = max(B[i-1]-1, A[i]);
            if(B[i] <= 0){
                return false;
            }
        }
        return true;
    }
anbuqun 

*/