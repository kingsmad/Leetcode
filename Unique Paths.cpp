#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unsigned long long mi = min(m-1, n-1);
        unsigned long long ma = max(m-1, n-1);

        unsigned long long result = 1;
        for(unsigned long long i=ma+1; i<mi+ma+1; ++i) {
        	result *= i;
        }

        unsigned long long tmp = 1;
        for(unsigned long long i=1; i<mi+1; ++i) {
        	tmp *= i;
        }

        return static_cast<int>(result / tmp);
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	int p1 = atoi(argv[1]);
	int p2 = atoi(argv[2]);
	cout << s.uniquePaths(p1, p2) << endl;
}