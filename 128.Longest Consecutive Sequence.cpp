/*************************************************************************
    > File Name: 128.Longest Consecutive Sequence.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Mon Apr  6 22:51:35 2015
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream> 
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int ans = 0;
        int len = num.size();
        unordered_set<int> mset;
        for(int i=0; i<len; ++i)
            if(mset.find(num[i]) == mset.end())
                mset.insert(num[i]);
        for(int i=0; i<len; ++i) {
            if(mset.find(num[i]) == mset.end())
                continue;
            int cnt = 0;
            int p = num[i];
            unordered_set<int>::iterator c;
            while((c = mset.find(p)) != mset.end()) {
                ++cnt;
                mset.erase(c);
                ++p;
            }
            p = num[i] - 1;
            while((c = mset.find(p)) != mset.end()) {
                ++cnt;
                mset.erase(p);
                --p;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    fstream in("/Developer/dat.txt");
    cin.rdbuf(in.rdbuf());
    int len;
    cin >> len;

    vector<int> num(len, 0);
    for(int i=0; i<len; ++i) 
        cin >> num[i];

    Solution sol; 
    int ans = sol.longestConsecutive(num);

    cout << "The answer is: " << ans << endl;

    return 0;
}
