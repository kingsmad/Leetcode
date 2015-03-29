#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = prices.size();
        
        vector<int> leftAns(len, 0);
        int mi = prices[0];
        leftAns[0] = 0;

        for(int i=1; i<len; ++i) {
            if(prices[i] < mi) {
                mi = prices[i];
                leftAns[i] = leftAns[i-1];
            }
            else
                leftAns[i] = max(leftAns[i-1], prices[i]-mi);
            
        }

        vector<int> rightAns(len, 0);
        int ma = prices[len-1];
        rightAns[len-1] = 0;

        for(int i=len-2; i>-1; --i) {
            if(prices[i] > ma) {
                ma = prices[i];
                rightAns[i] = rightAns[i+1];
            }
            else 
                rightAns[i] = max(rightAns[i+1], ma - prices[i]);
        }


        int ans = 0;
        for(int pv=0; pv<len-1; ++pv) {
            if(ans < leftAns[pv] + rightAns[pv])
                ans = leftAns[pv] + rightAns[pv];
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;

    vector<int> num(len, 0);
    for(int p=0; p<len; ++p) {
        cin >> num[p];
    }

    Solution s;
    cout << "the maxProfit is: " << s.maxProfit(num) << endl;
    return 0;
}