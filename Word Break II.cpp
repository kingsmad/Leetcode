#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution { 
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        ans_.clear();
        ssize_t len = s.size();
        vector<bool> dp(len+1, false); //dp[i]代表以i位置为end（不包括i）的前i个字符串是否能够匹配
        
        map<ssize_t, vector<ssize_t> > pre_map; //存放每个点的前驱
        
        dp[0] = true;
        
        for(ssize_t i=0; i<=len; ++i) {
            if(dp[i]) {
                for(ssize_t k=i; k<=len; ++k) {
                    if(dict.count(s.substr(i, k-i)) > 0) {
                        dp[k] = true;
                        pre_map[k].push_back(i);
                    }
                }
            }
        }
        
        
        if(!dp[len])
            return ans_;
        
        /*根据前驱，做出返回的所有路径*/
        vector<vector<ssize_t> > path;
        bool on_busy = true;
        vector<ssize_t> t1; t1.push_back(len);
        path.push_back(t1);
        
        while(on_busy) {
            on_busy = false;
            
            for(ssize_t i=0; i<path.size(); ++i) {
                ssize_t tmp = path[i].back();
                if(tmp != 0) {
                    vector<ssize_t>& pvec = pre_map[tmp];
                    ssize_t pre_vec_len = pvec.size();
                    ssize_t cur_len = path.size();
                    
                    ssize_t l = pre_vec_len - 1;
                    while(l--)
                        path.push_back(vector<ssize_t>(path[i]));
                    l = pre_vec_len - 1;
                    
                    path[i].push_back(pvec.front());
                    
                    vector<ssize_t>::iterator pre = pvec.begin() + 1;
                    for(ssize_t k=0; k<l; ++k) {
                        path[cur_len+k].push_back(*pre);
                        ++pre;
                    }
                    on_busy = true;
                }
            }
            
        }
        
        /*根据路径，做出所有的字符串，返回*/
        for(ssize_t i=0; i<path.size(); ++i) {
            string tmp;
            ssize_t plen = path[i].size();
            for(ssize_t k=plen-1; k>0; --k) {
                if(!tmp.empty())
                    tmp.append(" ");
                tmp.append(s.substr(path[i][k], path[i][k-1]-path[i][k]));
            }
            ans_.push_back(tmp);
        }
        
        return ans_;
    }
    
private:
    vector<string> ans_;
};


int main(int argc, char const *argv[])
{
    
    
    ifstream fin("/Users/liujuechen/Desktop/leetcode/dat.txt");
    
    unordered_set<string> dict;
    
    string w;
    fin >> w;
    
    string t;
    while(fin >> t) {
        dict.insert(t);
    }
    
    Solution s;
    vector<string> ans = s.wordBreak(w, dict);
    for(ssize_t i=0; i<ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    cout << endl;
    
    return 0;
}