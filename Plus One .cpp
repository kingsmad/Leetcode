#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<int> result(digits);
        int len = result.size();
        int pos = len - 1;
		
		++result[pos];
		while(pos > -1 && result[pos] == 10) {
			result[pos] = 0;
			if(pos > 0){
				--pos;
				++result[pos];
			}
		}

		if(result[0] == 0) {
			result.push_back(0);
			result[0] = 1;
		}
		return result;
    }
};

int main(int argc, char* argv[]) {
	std::vector<int> dc;
	for(int i=0; i<argc; ++i) {
		dc.push_back(atoi(argv[i]));
	}

	Solution s;
	std::vector<int> las(s.plusOne(dc));
	for(int j=0; j<argc; ++j) {
		std::cout << las[j] << std::endl;
	}
}