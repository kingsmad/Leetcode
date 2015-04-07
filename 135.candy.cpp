/*************************************************************************
    > File Name: 135.candy.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Mon Apr  6 21:26:40 2015
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        int candy[len];
        fill_n(candy, len, 1);

        for(int i=1; i<len; ++i) {
            if(ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
        }
        for(int i=len-2; i>=0; --i) {
            if(ratings[i] > ratings[i+1]) {
                candy[i] = max(candy[i], candy[i+1] + 1);
            }
        }

        int ans = 0;
        for(int i=0; i<len; ++i)
            ans += candy[i];
        return ans;
    }
};


int main(int argc, char** argv ) {
    int len;
    cin >> len;

    vector<int> ratings(len, 0);
    for(int i=0; i<len; ++i)
        cin >> ratings[i];

    Solution sol;
    int ans = sol.candy(ratings);

    cout << "The answer is: " << ans << endl;

    return 0;
}
