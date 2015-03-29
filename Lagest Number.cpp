#include <iostream>
#include <string>
#include <vector>

using namespace std;

class kgreater : public binary_function<string, string, bool> {
public:
	bool operator()(const string& s1, const string& s2) {
		int i = 0;
		int j = 0;
		while(i < s1.size() && j < s2.size()) {
			if(s1[i] < s2[j])
				return true;
			else if (s1[i] > s2[j])
				return false;
			++i; ++j;
		}

		return i == s1.size();
	}
};


class Solution {
public:
    string largestNumber(vector<int> &num) {
        
    }
};
