#include <vector>
#include <iostream>
#include <fstream>
#include <stack>
#include <set>
using namespace std;
class Solution {
public:
    Solution() {
        tmp_.resize(4);
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        ans_.clear();
        int len = num.size();
        sort(num.begin(), num.end());
        
        set<string> test;
        for(int i=0; i<len; ++i) {
            for(int j=i+1; j<len; ++j) {
                int ptarget = target - num[i] - num[j];
                vector<int>::iterator first = num.begin() + j + 1;
                vector<int>::iterator last = num.end() - 1;
                while(first < last ) {
                    if(*first + *last < ptarget)
                        ++first;
                    else if (*first + *last > ptarget)
                        --last;
                    else {
                        tmp_[0] = num[i];
                        tmp_[1] = num[j];
                        tmp_[2] = *first;
                        tmp_[3] = *last;
                        
                        string ss;
                        for(int k=0; k<3; ++k)
                            ss += num[k];
                        set<string>::iterator it = test.find(ss);
                        if(it == test.end()) {
                            sort(tmp_.begin(), tmp_.end());
                            ans_.push_back(tmp_);
                            test.insert(ss);
                        }
                        break;
                    }
                }
            }
        }

        return ans_;
    }
private:
    vector<vector<int> > ans_;
    vector<int> tmp_;

};

int main(int argc, char const *argv[])
{
    
    fstream in("data.rtf");
    cin.rdbuf(in.rdbuf());

    int len;
    cin >> len;
    int target;
    cin >> target;

    vector<int> A(len);
    for(int i=0; i<len; ++i)
        cin >> A[i];

    Solution s;
    vector<vector<int> > vec = s.fourSum(A, target);
    for(int i=0; i<vec.size(); ++i) {
        for(int j=0; j<vec[i].size(); ++j)
            cout << vec[i][j] << " ";
        cout << endl;
    }


    return 0;
}