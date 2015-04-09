/*************************************************************************
    > File Name: 37.Sudoku Solver.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  9 20:54:37 2015
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <setjmp.h>

//jmp_buf jbuf;
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        done = false;
        vector<pair<int, int> > buf;
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                if(board[i][j] == '.') {
                    buf.push_back(make_pair(i, j));
                }
            }
        }

        // if(setjmp(jbuf) == 0) 
        //     __dfs(0, buf, board);
        __dfs(0, buf, board);
        return;
    }

    void __dfs(int pos, vector<pair<int, int> >& buf, \
            vector<vector<char> >& board) {
        // if(pos == buf.size())
        //     longjmp(jbuf, 1);
        if(done || pos == buf.size()) {
            done = true;
            return;
        }
        int r = buf[pos].first;
        int c = buf[pos].second;
        for(char i='1'; i<='9'; ++i) {
            if(__check_row(r, c, i, board) && __check_col(r, c, i, board) &&\
                    __check_grid(r, c, i, board)) {
                board[r][c] = i;
                __dfs(pos+1, buf, board);
                if(done)
                    return;
                board[r][c] = '.';
            }
        }
    }

    bool __check_row(int r, int c, int v, vector<vector<char> >& board) {
        for(int i=0; i<9; ++i) {
            if(i != c && board[r][i] == v)
                return false;
        }

        return true;
    }

    bool __check_col(int r, int c, int v, vector<vector<char> >& board) {
        for(int i=0; i<9; ++i) {
            if(i != r && board[i][c] == v) 
                return false;
        }

        return true;
    }

    bool __check_grid(int r, int c, int v, vector<vector<char> >& board) {
        int r_grid = (r / 3 ) * 3;
        int c_grid = (c / 3) * 3;
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                if((r_grid+i != r || c_grid+j != c) && \
                board[r_grid+i][c_grid+j] == v)
                    return false;
            }
        }

        return true;
    }
private:
    bool done;
};

int main(int argc, char** argv ) {
    fstream in("/Developer/dat.txt");
    cin.rdbuf(in.rdbuf());
    vector<vector<char> > board(9, vector<char>(9, 0));
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }   

    cout << endl << endl;
    Solution sol;
    sol.solveSudoku(board);

    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }   

    return 0;
}
