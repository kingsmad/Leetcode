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
        

        vector<int> ans2;

        vector<int>* cur = &ans;
        vector<int>* next = &ans2;

        for(int st=0; st<rowIndex; ++st) {
            next->push_back(1);
            for(int i=0; i<st; ++i) {
                next->push_back((*cur)[i] + (*cur)[i+1]);
            }
            next->push_back(1);

            vector<int>* t = cur;
            cur = next;
            next = t;
            next->clear();
        }
        
        return *cur;
    }
};
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    Solution s;
    vector<int > vec = s.getRow(n);
    int len = vec.size();
    for(int i=0; i<len; ++i)
        cout << vec[i] << " ";
    cout << endl;
    return 0;
}