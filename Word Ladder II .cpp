#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

// class Solution {
// public:
//     vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        
//         map<string, vector<string> > pre_map;
//         vector<string> vec[2];
//         int cur = 0; int next = 1;
//         vector<unordered_set<string>::iterator> iters_to_erase;
        
//         vec[cur].push_back(start);
//         dict.erase(start);
//         int dth = 1;
        
//         bool got_it = false;
//         while(!vec[cur].empty() && !got_it) {
//         	++dth;
            
//         	for(ssize_t i=0; i<vec[cur].size(); ++i) {
//         		string tmp = vec[cur][i];
//         		ssize_t len = tmp.size();
//         		for(ssize_t j=0; j<len; ++j) {
//         			char c = tmp[j];
//         			for(char tc='a'; tc<='z'; ++tc) {
//         				if(tc != c) { //不与tmp自己相等
//         					tmp[j] = tc;
//         					auto it = dict.find(tmp);
//         					if(it != dict.end()) {
//         						if(tmp.compare(end) == 0)
//         							got_it = true;
//         						/*如果tmp还不在next中，则加入next序列*/
//                                 auto it_next = find(vec[next].begin(), vec[next].end(), *it);
//                                 if (it_next == vec[next].end()) {
//                                     vec[next].push_back(tmp);
//                                 }
                                
//         						/*如果还没标记it要被删除，则加入待删除队列*/
//                                 auto it_erase = find(iters_to_erase.begin(), iters_to_erase.end(), it);
//                                 if (it_erase == iters_to_erase.end()) {
//                                     iters_to_erase.push_back(it);
//                                 }
        						
//         						/*更新pre_map*/
//         						auto p = pre_map.find(tmp);
//         						if(p == pre_map.end()) {
//         							vector<string> tv;
//         							tv.push_back(vec[cur][i]);
//         							pre_map.insert(make_pair(tmp, tv));
//         						}
//         						else {
//         							vector<string>& v = p->second;
//         							v.push_back(vec[cur][i]);
//         						}
//         					}
//         				}
//         			}
//         			tmp[j] = c;
//         		}
                
//         	}
            
//         	vec[cur].clear();
//         	cur = !cur;
//         	next = !next;
            
//         	/*正式删除*/
//         	for (ssize_t i=0; i<iters_to_erase.size(); ++i) {
//                 dict.erase(iters_to_erase[i]);
//             }
//             iters_to_erase.clear();
//         }
        
        
//         vector<vector<string> > ans;
//         if(!got_it)
//         	return ans;
        
//         vector<string> tmp;
//         tmp.push_back(end);
//         ans.push_back(tmp);
        
//         bool go_on = true;
//         while(go_on) {
//         	ssize_t vlen = ans.size();
//         	go_on = false;
//         	for(ssize_t i=0; i<vlen; ++i) {
//         		if(ans[i].back() != start) {
//         			vector<string>& vt = pre_map.find(ans[i].back())->second;
//         			ssize_t vtlen = vt.size();
//                     ssize_t vlen1 = ans.size();
                    
//                     /*复制路径到尾部*/
//         			for(ssize_t r=0; r<vtlen-1; ++r) {
//         				ans.push_back(ans[i]);
//         			}
//                     /*将前驱添加到尾部*/
//         			ans[i].push_back(vt[0]);
//         			for(ssize_t j=1; j<vtlen; ++j) {
//         				ans[vlen1+j-1].push_back(vt[j]);
//         			}
//         			go_on = true;
//         		}
//         	}
//         }
        
//         for (ssize_t i=0; i<ans.size(); ++i) {
//             reverse(ans[i].begin(), ans[i].end());
//         }
//         return ans;
        
//     }
// };

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<unordered_set<string> > nodes(2);
        map<string, vector<string> > pre_map;
        int cur = 0;
        int next = 1;
        nodes[cur].insert(start);
        
        while(!nodes[cur].empty()) {
            for(auto i=nodes[cur].begin(); i!=nodes[cur].end(); ++i) {
                for(int k=0; k<i->size(); ++k) {
                    string str = *i;
                    for(char c='a'; c<='z'; ++c) {
                        if(c == str[k])
                            continue;
                        str[k] = c;
                        if(dict.find(str) != dict.end() && nodes[cur].find(str) == nodes[cur].end()) {
                            if(nodes[next].find(str) == nodes[next].end())
                                nodes[next].insert(str);
                            pre_map[str].push_back(*i);
                        }
                        str[k] = (*i)[k];
                    }
                }
            }
            
            if(nodes[next].find(end) != nodes[next].end())
                break;
                
            for(auto i=nodes[cur].begin(); i!=nodes[cur].end(); ++i)
                dict.erase(*i);
            nodes[cur].clear();
            cur = !cur;
            next = !next;
        }
        
        ans_.clear();
        path_.clear();
        path_.push_back(end);
        
        __Dfs(0, start, end, pre_map);
        
        return ans_;
    }
    
    void __Dfs(int pos, string& start, string& end, map<string, vector<string> >& pre_map) {
        if(path_[pos] == start) {
            ans_.push_back(vector<string>(path_.rbegin(), path_.rend()));
            return;
        }
        vector<string>& vec = pre_map[path_[pos]];
        for(int i=0; i<vec.size(); ++i) {
            path_.push_back(vec[i]);
            __Dfs(pos+1, start, end, pre_map);
            path_.pop_back();
        }
    }
private:
    vector<vector<string> > ans_;
    vector<string> path_;
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
        vector<vector<string> > ans = s.findLadders(start, end, sset);
        for(ssize_t i=0; i<ans.size(); ++i) {
        	for(ssize_t j=0; j<ans[i].size(); ++j)
        		cout << ans[i][j] << " ";
        }
        cout << endl;
    
    return 0;
}


