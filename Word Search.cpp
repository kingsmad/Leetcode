#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
    	ok_ = false;

    	int rlen = board.size();
    	if(rlen < 1)
    		return word.size() == 0;
    	int clen = board[0].size(); 
    	
    	vector<vector<bool> > visited(rlen, vector<bool>(clen, false));

    	for(int i=0; i<rlen; ++i) {
    		for(int k=0; k<clen; ++k) {
    			if(board[i][k] == word[0]) {
    				visited[i][k] = true;
    				__Dfs(i, k, 1, board, word, visited);
    				if(ok_)
    					return ok_;
    				visited[i][k] = false;
    			}
    		}
    	}

    	return ok_;
    }

	void __Dfs(int r, int c,  
			int pos, vector<vector<char> >& board, string& word, vector<vector<bool> >& visited) {
		
		if(pos == word.size()) {
			ok_ = true;
		}
		if(ok_)
			return;
		int rlen = board.size();
		int clen = board[0].size();

		if(r > 0 && !visited[r-1][c] && word[pos] == board[r-1][c]) {
			visited[r-1][c] = true;
			__Dfs(r-1, c, pos+1, board, word, visited);
			visited[r-1][c] = false;
		}
		if(c > 0 && !visited[r][c-1] && word[pos] == board[r][c-1]) {
			visited[r][c-1] = true;
			__Dfs(r, c-1, pos+1, board, word, visited);
			visited[r][c-1] = false;  
		}
		if(r+1 < rlen && !visited[r+1][c] && word[pos] == board[r+1][c]) {
			visited[r+1][c] = true;
			__Dfs(r+1, c, pos+1, board, word, visited);
			visited[r+1][c] = false;
		}
		if(c+1<clen && !visited[r][c+1] && word[pos] == board[r][c+1]) {
			visited[r][c+1] = true;
			__Dfs(r, c+1, pos+1, board, word, visited);
			visited[r][c+1] = false;
		}


	}    
private:
	bool ok_;
};

int main(int argc, char const *argv[])
{
	int rlen; int clen;
	string s1;
	cin >> rlen >> clen >> s1; 

	vector<vector<char> > board(rlen, vector<char>(clen, 0));
	for(int i=0; i<rlen; ++i) {
		for(int k=0; k<clen; ++k) {
			cin >> board[i][k];
		}
	}

	Solution sol;
	bool ans = sol.exist(board, s1);

	cout << ans << endl;
	return 0;
}