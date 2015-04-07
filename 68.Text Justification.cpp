/*************************************************************************
    > File Name: 68.Text Justification.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Mon Apr  6 18:13:09 2015
 ************************************************************************/


/*This problem not difinite enough, 
if the line is the last line, only 1 space will 
be used for gapping strings and left tail blank
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        vector<int> buf;
        int len = words.size();
        int first = 0;
        while(first < len) {
            buf.push_back(first);
            int cnt = words[first].size();
            int last = first + 1;
            while(last < len && cnt + words[last].size() + 1 <= L) {
                cnt += words[last].size() + 1;
                buf.push_back(last);
                ++last;
            }
            
            __process(words, L, buf, ans, last==len);

            buf.clear();
            first = last;
        }

        return ans;
    }

    void __process(vector<string>& words, int L, vector<int>& buf, \
            vector<string> &ans, bool last_line) {
         int cnt = 0;
         int len = buf.size();
        string res;
         if(len == 1) {
             string str = words[buf[0]];
             str += string(L-str.size(), ' ');
             ans.push_back(str);
             return;
         }
         if(last_line) {
            for(int i=0; i+1<len; ++i) {
                res += words[buf[i]];
                res += " ";
            }
            res += words[buf[len-1]];
            res += string(L-res.size(), ' ');
            ans.push_back(res);
            return;
         }
         for(int i=0; i<len; ++i) 
             cnt += words[buf[i]].size();
         int gap = ( L - cnt) / (len -1);
         int rd = (L - cnt ) % (len - 1);
         for(int i=0; i+1<len; ++i) {
            res += words[buf[i]];
            int c = (i < rd) ? gap + 1 : gap;
            res += string(c, ' ');
         }
         res += words[buf[len-1]]; 

         ans.push_back(res);
         return;
    }
};

int main(int argc, char const *argv[])
{
    
    ifstream in("/Developer/dat.txt");
    cin.rdbuf(in.rdbuf());
    int len;
    cin >> len;
    int L;
    cin >> L;
    vector<string> words(len);
    
    for(int i=0; i<len; ++i)
        cin >> words[i];
    
    Solution sol;
    vector<string> ans = sol.fullJustify(words, L);
    
    for(int i=0; i<ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    // cout << ans.size() << "size of ans is :" << endl;
    cout << endl;
    return 0;
}