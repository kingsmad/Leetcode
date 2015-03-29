#include <iostream>
#include <vector>
#include <string>


using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2)
        	return s;
        
        vector<char> str;
        bool sharp = false;
        for(int i=0; i<s.size();) {
        	if(sharp)
        		str.push_back(0);
        	else{
        		str.push_back(s[i]);
        		++i;
        	}
        	sharp = !sharp;
        }
        
        int len = str.size();
        vector<int> range(len, 0);
        int most = 0;
        for(int i=1; i<len; ++i) {
            int t = 0;
            if(i>most && i<=most+range[most])
                t = range[2*most-i];
            
            //语义是t已经可以，如果t+1可以则+1;
        	while(i-t-1>=0 && i+t+1<len && str[i-t-1] == str[i+t+1]) {
        		++t;
        	}
            
        	range[i] = t;
            
            if(i+range[i] > most+range[most])
                most = i;
        }
        
        int ans = 0;
        for(int i=0; i<len; ++i) {
        	ans = (range[ans] > range[i]) ? ans : i;
        }
        
        if(range[ans] == 0)
            return "";
        
        string res;
        for(int i=ans-range[ans]; i<=ans+range[ans]; ++i) {
        	if(str[i] != 0)
        		res.push_back(str[i]);
        }
        
        return res;
    }
};

int main(int argc, char const *argv[])
{
	string s1;
	cin >> s1;
    
	Solution sol;
	string s2 = sol.longestPalindrome(s1);
    
	cout << s2 << endl;
	return 0;
}