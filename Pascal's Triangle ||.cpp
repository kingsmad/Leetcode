#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) { 
        vector<int> ans;
        if(rowIndex < 0)
            return ans;
            
        ans.push_back(1);
        if(rowIndex == 0)
            return ans;
        
        ans.push_back(1);
        if(rowIndex == 1)
            return ans;
        
        ans.resize(rowIndex+1, 1);
        for(int cur=1; cur != rowIndex; ++cur) {  
            for(int i=1; i<cur; ++i)
                ans[i] = ans[i] + ans[i+1];
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