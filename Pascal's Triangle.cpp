#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ans;
        ans.push_back(vector<int>(1, 1));
        if(numRows < 2)
        	return ans;

       	vector<int> t;
       	t.push_back(1);
       	t.push_back(2);
       	t.push_back(1);
       	ans.push_back(t);

        int cur = 1;
        int next = 2;
        while(next < numRows) {
            vector<int> tmp;
            tmp.push_back(1);
            
            int cur_len = ans[cur].size();
            for(int i=0; i<cur_len-1; ++i)
                tmp.push_back(ans[cur][i] + ans[cur][i+1]);
            
            tmp.push_back(1);
            
            ++cur;
            ++next;

  			ans.push_back(tmp);
        }
        
        return ans;
    }
};


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	Solution s;
	vector<vector<int> > vec = s.generate(n);

	int vecLen = vec.size();
	for(int i=0; i<vecLen; ++i) {
		int v = vec[i].size();
		for(int j=0; j<v; ++j) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}