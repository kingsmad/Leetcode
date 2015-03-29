#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<char> tmp;
        for(int i=0; i<9; ++i) {
            if(!__Isvalid(board[i]))
                return false;
        }
        
        for(int i=0; i<9; ++i) {
            tmp.clear();
            for(int k=0; k<9; ++k) {
                tmp.push_back(board[k][i]);
            }
            if(!__Isvalid(tmp))
                return false;
        }
        
        for(int i=0; i<9; i=i+3) {
            for(int k=0; k<9; k=k+3) {
                tmp.clear();
                for(int t1=0; t1<3; ++t1) {
                    for(int t2=0; t2<3; ++t2) {
                        tmp.push_back(board[i+t1][k+t2]);
                    }
                }
                if(!__Isvalid(tmp))
                    return false;
            }
        }
        
        return true;
    }
    
    bool __Isvalid(vector<char>& vec) {
        int pool[9];
        fill(pool, pool+9, 0);
        
        for(int i=0; i<vec.size(); ++i) {
            if(vec[i] == '.')
                continue;
            if(pool[vec[i]-1-'0'] == 1)
                return false;
            else {
                pool[vec[i]-1-'0'] = 1;
            }
        }
        
        return true;
    }
};

int main(int argc, char const *argv[])
{
    if(!argv[1])
        return 0;

    ifstream in(argv[1]);
    cin.rdbuf(in.rdbuf());

    vector<vector<char> > board(9, vector<char>(9));
    for(int i=0; i<9; ++i) {
        for(int k=0; k<9; ++i) {
            cin >> board[i][k];
        }
    }

    
    Solution sol;
    bool right = sol.isValidSudoku(board);
    const char* res = right ? "true" : "false";

    printf("\nThe result is %s\n", res);

    return 0;
}