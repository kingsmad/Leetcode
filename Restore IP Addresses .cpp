#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        ans_.clear();
        str_ = &s;
        len_ = str_->size();
        
        if(len_ < 7 || len_ > 15)
            return ans_;
        vector<char> tmp(20);
        
        __dfs(tmp, 0, 0);
        
        return ans_;
    }
    
    void __dfs(vector<char>& tmp, int cur_index, int seg_cnt) {
        if(cur_index == len_) {
            if(seg_cnt == 4) {
                ans_.push_back(string(tmp.begin(), tmp.end()));
                return;
            }
        }
        else {
            if(seg_cnt == 4)
                return;
            int sum = 0;
            for(int i=cur_index; i<len_ && i<cur_index+3; ++i) {
                sum *= 10;
                sum += str_->at(i) - '0';
                if(sum > 255)
                    break;
                if(cur_index != 0)
                    tmp.push_back('.');
                tmp.push_back(str_->at(i));
                __dfs(tmp, i, seg_cnt+1);
                tmp.pop_back();
            }
            
        }
        
    }
private:
    vector<string> ans_;    /*返回的结果*/
    string* str_;   /*将要处理的原始string*/
    int len_;   /*m_str的长度*/
};

int main(int argc, char const *argv[])
{
    string str ;
    cin >> str;

    Solution s;
    vector<string> ans = s.restoreIpAddresses(str);

    for(int i=0; i<ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}