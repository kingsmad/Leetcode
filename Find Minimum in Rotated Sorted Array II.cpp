/*************************************************************************
    > File Name: Find Minimum in Rotated Sorted Array II.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  2 16:10:00 2015
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
	if(num.size() < 1)
	    return 0;
	int first = 0;
	int end = num.size() - 1;
	while(first < num.size() && num[first] == num[end])
	    ++first;
	if(first == num.size())
	    return num[0];
	if(first == end || num[first] < num[end])
	    return num[first];
	
	while(first < end) {
	    if(num[first] <= num[end])
		return num[first];
	    int half = (first + end) / 2;
	    if(num[half] >= num[first]) {
		first = half + 1;
	    } else {
		end = half;
	    }
	}

	return num[first];
    }
};


int main(int argc, char** argv) {
    int len ;
    cin >> len;

    vector<int> vec(len, 0);
    for(int i=0; i<vec.size(); ++i) {
	cin >> vec[i];
    }

    Solution sol;
    int ans = sol.findMin(vec);

    cout << "\nThe answer is " << ans << endl;

    return 0;
}
