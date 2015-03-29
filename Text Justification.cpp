#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        for(int i=0; i<words.size(); ) {
            int total = 0;
            int first = i;
            for(; i<words.size(); ++i) { //此时total只是检查能否放得下
                if(total != 0)
                    ++total;
                total += words[i].size();
                if(total > L)
                    break;
            }
            vector<char> str(L, ' ');
            __Produce(first, i, str, words);
            ans.push_back(string(str.begin(), str.end()));
        }
        
        return ans;
    }
    
    void __Produce(int first, int last, vector<char>& str, vector<string>& words) {
        int L = str.size();
        vector<char>::iterator ps = str.begin();
        vector<char>::iterator pe = str.end();
        
        if(first + 1== last) {
            string& tmp = words[last-1];
            copy(tmp.begin(), tmp.end(), ps);
            return;
        }
        
        bool is_last_line = (last == words.size());
        if(!is_last_line) { //not last line 对齐;
            string& tmp = words[last-1];
            pe -= tmp.size();
            copy(tmp.begin(), tmp.end(), pe);
            --last;
            L -= tmp.size();
        }
        
        int total = 0;
        for(int i=first; i<last; ++i)
            total += words[i].size();
        
        int c = (is_last_line) ? 1 : ((L - total) / (last - first ));
        int r = (is_last_line) ? 0 : (L - total - c * (last - first ));
        
        for(int i=first; i<last; ++i) {
            copy(words[i].begin(), words[i].end(), ps);
            ps += words[i].size() + c + ((r-- > 0) ? 1:0);
        }
        
        return ;
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