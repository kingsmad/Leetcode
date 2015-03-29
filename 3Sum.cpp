#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ans;
        if(num.size() < 3)
            return ans;
        sort(num.begin(), num.end());
        int len = num.size();
        for(int i=0; i<len; ) {
            for(int j=len-1; j>i+1; ) {
                int sum = -(num[i] + num[j]);
                if(binary_search(num.begin()+i+1, num.begin()+j, sum)) {
                    vector<int> tmp ;
                    tmp.push_back(num[i]);
                    tmp.push_back(sum);
                    tmp.push_back(num[j]);
                    ans.push_back(tmp);
                }
                int t = num[j];
                while(j>i+1 && num[j] == t)
                    --j;
            }
            int t = num[i];
            while(i<len && num[i] == t)
                ++i;
        }

        return ans;
    }

};

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;

    vector<int> A(len);
    for(int i=0; i<len; ++i)
        cin >> A[i];

    Solution s;
    vector<vector<int> > vec = s.threeSum(A);
    for(int i=0; i<vec.size(); ++i) {
        for(int j=0; j<vec[i].size(); ++j)
            cout << vec[i][j] << " ";
        cout << endl;
    }


    return 0;
}