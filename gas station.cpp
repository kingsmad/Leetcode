class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = gas.size();
        int final[n];
        for(int i=0; i<n; ++i) {
        	final[i] = gas[i] - cost[(n+i-1)%n];
        }

        int cur = 0;
        for(; cur<n;) {
        	int total = gas[cur];
        	
        }


    }
};