#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> vec;
        set<int> mSet;
        for(int i=0; i<n; ++i)
            mSet.insert(i+1);
        --k;
        for(int i=0; i<n; ++i) {
            int tmp = k / facts[n-i-2];
            k -= tmp * facts[n-i-2];
            set<int>::iterator it = mSet.begin();
            while (tmp-- > 0)
                ++it;
            vec.push_back(*it + 48);
            mSet.erase(it);
        }
        
        string ans(vec.begin(), vec.end());
        
        return ans;
    }
    
    Solution() {
        int tmp = 1;
        for(int i=1; i<9; ++i) {
            tmp *= i;
            facts.push_back(tmp);
        }
    }
    
private:
    vector<long> facts;
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    
    int k;
    cin >> k;
    
    Solution s;
    string s1 = s.getPermutation(n, k);
    
    cout << s1 << endl;
    
    return 0;
}