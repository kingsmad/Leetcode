#include <iostream>

using namespace std;

class Solution {
public:
	bool search(int A[], int n, int target) {
		int p = 0;
		int q = n-1;
		while(q > p && A[q] == A[p])
			--q;
		n = q - p + 1;
		int len = n;

		while(p < q && A[p] >= A[q]) {
			int half = (p + q) / 2;
			if(A[half] >= A[p])
				p = half + 1;
			else
				q = half;
		}

		while(len > 0) {
			int half = len >> 1;
			int pos = (p + half) % n;
			if(A[pos] > target) {
				len = half;
			}
			else if(A[pos] < target) {
				p = pos + 1;
				len = len - half - 1;
			}
			else
				return true;
		}

		return false;
	}
};

int main(int argc, char** argv) {
	int len;
	cin >> len;
	int target;
	cin >> target;

	int A[len];
	for(int i=0; i<len; ++i) 
		scanf("%d", A+i);
	
	Solution sol;
	bool ans = sol.search(A, len, target);
	const char* str = ans ? "true" : "false";

	printf("The array contains the target? : %s", str);

	return 0;
}
