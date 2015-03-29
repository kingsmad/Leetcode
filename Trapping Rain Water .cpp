class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(A == NULL || n < 3)
        	return 0;
        int totalWater = 0;

        int first = 0;
        while(A[first] < A[first+1] && first < n-1)
            ++first;
        if(first == n-1)
            return 0;

        int cur = first;
        while(true) {
            int next = cur + 1;
            while(next < n && A[next] < A[cur] )
                ++next;
            if(next == n)
                break;
            else {
                for(int i=cur; i<next; ++i) {
                    totalWater += A[cur] - A[i];
                }
                cur = next;
            }
        }

        while(cur < n-1) {
            int next = cur + 1;
            for(int i=cur+1; i<n; ++i)
                if(A[i] > A[next])
                    next = i;
            for(int i=cur+1; i<=next; ++i){
                totalWater += A[next] - A[i];
            }
            cur = next;
        }

        return totalWater;
    }
};