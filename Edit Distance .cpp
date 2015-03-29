#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len1 = word1.size();
        int len2 = word2.size();

        int dp[len1+1][len2+1];
        for(int i=0; i<len2+1; ++i)
        	dp[0][i] = i;
        for(int j=0; j<len1+1; ++j)
        	dp[j][0] = j;


        for(int i=1; i<len1+1; ++i)
        	for(int j=1; j<len2+1; ++j){
        		int cmp = (word1[i-1] == word2[j-1]) ? 0:1;
        		int p1 = dp[i-1][j] + 1;
        		int p2 = dp[i][j-1] + 1;
        		int p3 = dp[i-1][j-1] + cmp;

        		dp[i][j] = min(min(p1, p2), p3);
        		// printf("dp[%d][%d] is %d, and p1 is %d; p2 is %d; p3 is %d; cmp is %d\n", i, j
        		// , dp[i][j], p1, p2, p3, cmp );
        	}
        return dp[len1][len2];
    }

};
/*注意：
	特别牢记本例中，状态是从“没有字符”开始，因而dp[0][j]的意思应该说要设定为0指向“没有字符”的用意。
	而不是说从0为index开始。

	word1[i] == word2[j]  ==为正时候，符号返回值肯定是1 切记
	其次，dp[0][0]的初始条件也要想清楚。
	dp[i][j] 的含义是：word1的前i个 和 word2的前j个 之间的距离是多少
	0代表说没有元素 ：即前0个的意思
*/
int main(int argc, char* argv[]) {
	Solution s ;
	if(argc < 2)
		return 0;
	string s1(argv[1]);
	string s2(argv[2]);
	int re = s.minDistance(s1, s2);
	cout << s1 << " and " << s2 << " distance is " << re << endl;
}



/*注意：
	特别牢记本例中，状态是从“没有字符”开始，因而dp[0][j]的意思应该说要设定为0指向“没有字符”的用意。
	而不是说从0为index开始。

	word1[i] == word2[j]  ==为正时候，符号返回值肯定是1 切记
	其次，dp[0][0]的初始条件也要想清楚。



*/