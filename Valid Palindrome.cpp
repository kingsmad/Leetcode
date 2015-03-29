#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	int len = s.size();
    	char buf[len];
    	int buf_len = 0;
    	for(int i=0; i<len; ++i) {
    		int tmp = __ProcChara(s[i]);
    		if(tmp != -1) {
    			buf[buf_len++] = tmp;
    		}
    	}

    	int k=0; int j=buf_len-1;
    	while(k < j) {
    		if(buf[k] != buf[j])
    			return false;
    		++k;
    		--j;
    	}

    	return true;
    }

private:
	/*判断char的状态，如果是大写字母返回1，小写返回0，非法则是-1*/
	int __ProcChara(char c) {
		if(c >= 'a' && c<='z')
			return c;
		else if(c >= 'A' && c <= 'Z')
			return c-'A'+'a';
		else if(c >= '0' && c <= '9')
			return c;
		else 
			return -1;
	}
};


int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	Solution sol;
	bool ans = sol.isPalindrome(str);
	cout << "ans is :" << ans << endl;

	return 0;
}