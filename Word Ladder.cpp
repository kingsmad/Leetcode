#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start.compare(end) == 0)
            return 1;

        vector<string> vec[2];
        int cur = 0;
        int next = 1;
        int dth = 1;
        vec[cur].push_back(start);
        dict.erase(start);
        while(!vec[cur].empty()) {
            ++dth;
            int vsize = vec[cur].size();
            
            for(ssize_t i=0; i<vsize; ++i) {
                string tmp = vec[cur][i];
                int word_size = tmp.size();
                for(ssize_t j=0; j<word_size; ++j) {
                    char c = tmp[j];
                    for(char k='a'; k<='z'; ++k) {
                        if(k != c) {
                            tmp[j] = k;
                            unordered_set<string>::iterator it = dict.find(tmp);
                            if(it != dict.end()) {
                                if(it->compare(end) == 0)
                                    return dth;
                                vec[next].push_back(tmp);
                                dict.erase(it);
                            }
                        }
                    }
                    tmp[j] = c;
                }
            }
            
            vec[cur].clear();
            cur = !cur;
            next = !next;
        }
        
        return 0;
    }
};
int main(int argc, char const *argv[])
{
        

        ifstream fin("/Users/liujuechen/Desktop/leetcode/dat.txt");

        unordered_set<string> sset;

        string start;
        string end;
        fin >> start;
        fin >> end;

        string t;
        while(fin >> t) {
            sset.insert(t);
        }
    
        Solution s;
        cout << "result is: " << s.ladderLength(start, end, sset) << endl;
    
    return 0;
}