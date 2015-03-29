#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> pool;
        for(int i=0; i<num2.size(); ++i) {
            pool.push_back(__MultiSingle(num1, num2[i]-'0'));
        }
        
        for(int i=0; i+1<pool.size(); ++i) {
            pool[i+1] = __MalPlus(pool[i], pool[i+1]);
        }
        
        string& ans = pool.back();
        int p = 0;
        while(p+1 < ans.size() && ans[p] == '0')
            ++p;
        return ans.substr(p, ans.size());
    }
    string __MultiSingle(string num, int n) {
        int carry = 0;
        for(int i=num.size()-1; i>=0; --i) {
            int tmp = (num[i]-'0') * n + carry;
            carry = tmp / 10;
            tmp -= carry * 10;
            
            num[i] = tmp + '0';
        }
        
        string ans;
        if(carry > 0)
            ans.push_back(carry + '0');
        ans += num;
        
        return ans;
    }
    
    string __MalPlus(string s1, string s2) {
        int len = max(s1.size()+1, s2.size()) + 1;
        string vec1(len, '0');
        string vec2(len, '0');
        copy(s2.begin(), s2.end(), vec1.end()-s2.size());
        copy(s1.begin(), s1.end(), vec2.end()-s1.size()-1);
        
        int carry = 0;
        for(int i=len-1; i>=0; --i) {
            int tmp = (vec1[i]-'0' + vec2[i]-'0' + carry);
            carry = tmp / 10;
            tmp -= carry * 10;
            
            vec2[i] = tmp + '0';
        }
        
        int p = 0;
        while(p < len && vec2[p] == '0')
            ++p;
        if(p == len)
            return "0";
        else
            return vec2.substr(p, len);
    }
};

int main(int argc, char const *argv[])
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    Solution sol;
    string ans = sol.multiply(s1, s2);
    
    cout << ans << endl;
    
    return 0;
}