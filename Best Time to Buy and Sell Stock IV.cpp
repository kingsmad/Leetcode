#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        vector<int> buf[2];
        int pre = 0;
        int cur = 1;
        buf[0].resize(len+1, 0);
        buf[1].resize(len+1, 0);

        while(k--) {
        	for(int j=1; j<=len; ++j) {
        		int tk = 0;
        		for(int d=0; d<j; ++d) {
        			tk = max(buf[pre][d] + prices[j-1] - prices[d], tk);
        			tk = max(tk, buf[cur][d]);
        		}
        		buf[cur][j] = tk;
        	}
        	cur = !cur;
        	pre = !pre;
        }

        return buf[pre][len];
    }
};

int main(int argc, char** argv) {
	int len;
	vector<int> prices;
	cout << "\nPlease enter array length:";
	cin >> len;
	cout << "\nPlease enter array :";
	for(int i=0; i<len; ++i) {
		int t;
		cin >> t;
		prices.push_back(t);
	}
	cout << "\nPlease enter transaction times:";
	int k;
	cin >> k;
	Solution sol;
	int ans = sol.maxProfit(k, prices);

	cout << "\nThe answer is : " << ans << endl;
}