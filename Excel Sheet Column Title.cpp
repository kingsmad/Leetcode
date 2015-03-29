/*************************************************************************
    > File Name: Excel Sheet Column Title.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Wed Mar 25 22:36:18 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
	string str;
	while(n) {
	    int rd = (n-1) % 26;
	    n = (n - rd) / 26;
	    str.push_back(rd + 'A');

	}

	return string(str.rbegin(), str.rend());
    }
};


int main(int argc, char** argv) {
    Solution sol;
    int n;
    cin >> n;

    string ans = sol.convertToTitle(n);

    cout << ans << endl;
}

