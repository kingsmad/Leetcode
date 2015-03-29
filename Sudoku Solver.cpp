#include <setjmp.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

jmp_buf gl_env;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        done = false;
//        if(setjmp(gl_env) == 0)
//          __Dfs(0, 0, board);
//        else {
//            cout << "here" << endl;
//        }
        __Dfs(0, 0, board);
        return;
    }
    
    void __Dfs(int row, int col, vector<vector<char> >& board) {
        if (done) {
            return;
        }
        int rlen = board.size();
        int clen = board[0].size();
        
//      if(row == rlen)
//          longjmp(gl_env, 1);
        if(row == rlen) {
            done = true;
            return;
        }
        
        if(board[row][col] != '.') {
            if(col == 8) {
                __Dfs(row+1, 0, board);
            }
            else
                __Dfs(row, col+1, board);
            return;
        }
        
        
        for(int i=1; !done && i<10; ++i) {
            if(checkCol(row, col, i+'0', board) &&
                checkRow(row, col, i+'0', board) &&
               checkGrid(row, col, i+'0', board))
            {
                board[row][col] = i+'0';
                if(col == 8) {
                    __Dfs(row+1, 0, board);
                }
                else
                    __Dfs(row, col+1, board);
                if (done) {
                    break;
                }
                board[row][col] = '.';
            }
        }
        
    }
    
    bool checkRow(int row, int col, int num, vector<vector<char> >& board) {
        for(int k=0; k<9; ++k) {
            if(k!=row && board[k][col] == num)
                return false;
        }
        
        return true;
    }
    
    bool checkCol(int row, int col, int num, vector<vector<char> >& board) {
        for(int k=0; k<9; ++k) {
            if(k!=col && board[row][k] == num)
                return false;
        }
        
        return true;
    }
    
    bool checkGrid(int row, int col, int num, vector<vector<char> >& board) {
        int t1 = (row/3) * 3;
        int t2 = (col/3) * 3;
        
        for(int i=0; i<3; ++i) {
            for(int k=0; k<3; ++k) {
                if((t1+i != row || t2+k != col) && board[t1+i][t2+k] == num)
                    return false;
            }
        }
        
        return true;
    }
private:
    bool done;
};

int main(int argc, char const *argv[])
{
    ifstream in("/Developer/dat.txt");
    cin.rdbuf(in.rdbuf());
    
    
    vector<vector<char> > board(9, vector<char>(9));
    for(int i=0; i<9; ++i) {
        for(int k=0; k<9; ++k) {
            cin >> board[i][k];
        }
    }
    
    Solution sol;
    sol.solveSudoku(board);
    
    for(int i=0; i<9; ++i) {
        for(int k=0; k<9; ++k) {
            cout << board[i][k] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}