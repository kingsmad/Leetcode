class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = ratings.size();
        int result = 0;
        int candys[len];
        fill_n(candys, len, 1);

        for(int i=1; i<len; ++i) {
        	if(ratings[i] > ratings[i-1])
        		candys[i] = candys[i-1] + 1;
        }

        for(int i=len-2; i>=0; --i) {
        	if(ratings[i] > ratings[i+1])
        		candys[i] = max(candys[i+1] + 1, candys[i]);
        }

        for(int j=0; j<len; j++) {
        	result += candys[j];
        }

        return result;
    }
};