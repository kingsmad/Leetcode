#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        vector<char> s1;
        s1.push_back('1');
        vector<char> s2;

        vector<char>* cur = &s1;
        vector<char>* next = &s2;
        
        while(--n > 0) {
        	int len = cur->size();
        	int cnt = 0;
        	char sc = (*cur)[0];

        	for(int p=0; p<len; ++p) {
        		char c = (*cur)[p];
        		if(c == sc) {
        			++cnt;
        		}
        		else {
        			next->push_back(cnt + '0');
        			next->push_back(sc);
        			cnt = 1;
        			sc = c;
        		}

        	}
        	
        	next->push_back(cnt + '0');
        	next->push_back(sc);

        	cur->clear();
        	vector<char>* tmp = cur;
        	cur = next;
        	next = tmp;
        }

        return string(cur->begin(), cur->end());
    }
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	Solution s;
	string s1 = s.countAndSay(n);
	int len = s1.size();
	for(int i=0; i<len; ++i) 
		cout << s1[i];
	cout << endl;


	return 0;
}