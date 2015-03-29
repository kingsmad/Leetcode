#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, vector<int> > map;
        unordered_map<char, int> map_cnt;
        vector<int> next(S.size(), -1);
        
        for(int i=0; i<T.size(); ++i) {
            map_cnt[T[i]] += 1;
            auto it = map.find(T[i]);
            if(it == map.end())
                map.insert(make_pair(T[i], vector<int>()));
        }
        
        for(int i=0; i<S.size(); ++i) {
            auto it = map.find(S[i]);
            if(it != map.end())
                it->second.push_back(i);
        }
        for(auto c=map.begin(); c!=map.end(); ++c) {
            vector<int>& vec = c->second;
            for(int i=0; i+1<vec.size(); ++i) {
                next[vec[i]] = vec[i+1];
            }
        }
        
        int first = 0;
        while(first < S.size()) {
            auto c = map.find(S[first]);
            if(c != map.end()) {
                break;
            }
            ++first;
        }
        int last = first;
        int cnt = 0;
        while(cnt < T.size() && last < S.size()) {
            auto c = map_cnt.find(S[last]);
            if(c != map_cnt.end() && --c->second >= 0)
                ++cnt;
            ++last;
        }
        if(last == S.size() && cnt < T.size())
            return "";
        
        while(first < last) {
            auto c = map_cnt.find(S[first]);
            if(c != map_cnt.end()) {
                if(c->second + 1 > 0)
                    break;
                else
                    ++c->second;
            }
            ++first;
        }
        
        
        int ans_first = first;
        int ans_last = last;
        
        while(true) {
            int p = first;
            while(p != -1 && p < last) {
                p = next[p];
            }
            if(p == -1)
                break;
            ++p;
            
            while(last < p) {
                auto c = map_cnt.find(S[last]);
                if(c != map_cnt.end())
                    --c->second;
                ++last;
            }
            for(; first<p; ) {
                auto c = map_cnt.find(S[first]);
                if(c != map_cnt.end()) {
                    if(c->second < 0) {
                        ++c->second;
                    }
                    else
                        break;
                }
                ++first;
            }
            
            if(last - first < ans_last - ans_first) {
                ans_first = first;
                ans_last = last;
            }
        }
        
        
        return S.substr(ans_first, ans_last-ans_first);
    }
};

int main(int argc, char const *argv[])
{
  string s1;
  string s2;
  cin >> s1 >> s2;

  Solution sol;
  string ans = sol.minWindow(s1, s2);

  cout << ans << endl;
  return 0;
}