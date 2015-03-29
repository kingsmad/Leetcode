#include <stack>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = prices.size();
        int ans = 0;
        
        stack<int> m_stack;
        m_stack.push(prices[0]);
        
        for(int p=1; p<len; ++p) {
            if(prices[p] <= m_stack.top())
                m_stack.push(prices[p]);
        }
        
        for(int q=len-1; q>-1; --q) {
            if(prices[q] > m_stack.top()) {
                ans = max(prices[q] - m_stack.top(), ans);
            }
            else {
                m_stack.pop();
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;

    vector<int> num(len, 0);
    for(int i=0; i<len; ++i) 
        cin >> num[i];

    Solution s;
    cout << "max profit is: " << s.maxProfit(num) << endl;
    return 0;
}