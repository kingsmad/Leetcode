#define MINE 1

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<vector<int> > ans;
    int index[10];
    bool flag[10];
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        ans.clear();
        memset(index, 0, sizeof(index) * 10);
        memset(flag, false, 10);
        
        int len = num.size();
        if(len < 1)
            return ans;
        /*排序保证从小到大*/
        sort(num.begin(), num.end());

        __dfs(len, 0, num);
        return ans;
    }

//    void __dfs(int len, int cnt, vector<int>& num) {
//        if(cnt == len) {
//            vector<int> tmp;
//            for(int i=0; i<len; ++i)
//                tmp.push_back(num[index[i]]);
//            ans.push_back(tmp);
//        }
//        else {
//            for(int i=0; i<len; ++i) {
//                if(flag[i] == false) {
//                    flag[i] = true;
//                    index[cnt] = i;
//                    __dfs(len, cnt+1, num);
//                    flag[i] = false;
//                    while (i<len-1 && num[i] == num[i+1])
//                        ++i;
//                }
//            }
//        }
//    }
    void __dfs(int len,int cnt,vector<int> &num)
    {
        if(cnt==len)
        {
            vector<int > t;
            for(int i=0; i<len; ++i)
                t.push_back(num[index[i]]);
            ans.push_back(t);
            return;
        }
        for(int i=0;i<len;++i)
        {
            if(flag[i]==false)
            {
                flag[i] = true;
                index[cnt]=i;
                __dfs(len,cnt+1,num);
                flag[i]=false;
                while(i<len-1 && num[i+1] == num[i])
                    ++i;
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    int len;
    cin >> len;
    
    vector<int> num(len);
    for(int i=0; i<len; ++i) {
        cin >> num[i];
    }
    
    Solution s;
    vector<vector<int> > ans;
    ans = s.permuteUnique(num);
    
    int asize = ans.size();
    for(int i=0; i<asize; ++i) {
        int csize = ans[i].size();
        for(int k=0; k<csize; ++k)
            cout << ans[i][k] << " ";
        cout << endl;
    }
    
    
    return 0;
}