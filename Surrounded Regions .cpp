#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char> > &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = board.size();
        
        for(int i=0; i<len; ++i) {
        	if(board[0][i] == 'O')
        		__search(board, 0, i);
        	if(board[len-1][i] == 'O')
        		__search(board, len-1, i);
        	if(board[i][0] == 'O')
        		__search(board, i, 0);
        	if(board[i][len-1] == 'O')
        		__search(board, i, len-1);
        }
        
        for(int i=0; i<len; ++i) {
        	for(int j=0; j<len; ++j) {
        		if(board[i][j] == 'A')
        			board[i][j] = 'O';
        		else if(board[i][j] == 'O')
        			board[i][j] = 'X';
        	}
        }
    }
    
    void __search(vector<vector<char> > &board, int row, int col)
    {
    	int len = board.size();
        
    	stack<pair<int, int> > mstack;
    	mstack.push(make_pair(row, col));
        
    	while(!mstack.empty())
    	{
    		int i = mstack.top().first;
    		int j = mstack.top().second;
    		mstack.pop();
    		board[i][j] = 'A';
            
    		if(i != 0 && board[i-1][j] == 'O')
    			mstack.push(make_pair(i-1, j));
    		
    		if(i != len-1 && board[i+1][j] == 'O')
    			mstack.push(make_pair(i+1, j));
    		
    		if(j != 0 && board[i][j-1] == 'O')
    			mstack.push(make_pair(i, j-1));
            
    		if(j != len-1 && board[i][j+1] == 'O')
    			mstack.push(make_pair(i, j+1));
    	}
    }
    
};


int main(int argc, char const *argv[])
{
    
//     fstream file("/Users/liujuechen/Desktop/dat.txt");
 //    cin.rdbuf(file.rdbuf());
    int len;
    cin >> len;
    
    vector<vector<char> > ans;
    vector<char> tmp;
    tmp.resize(len);
    
    for(int i=0; i<len; ++i) {
        for(int k=0; k<len; ++k)
            cin >> tmp[k];
        ans.push_back(tmp);
        tmp.clear();
        tmp.resize(len);
    }
    
    cout << "now the original is  :" << endl;
    for(int i=0; i<len; ++i) {
        for(int k=0; k<len; ++k)
            cout << ans[i][k] << " ";
        cout << endl;
    }
    
    
    Solution s;
    s.solve(ans);
    
    cout << "now after process is :" << endl;
    for(int i=0; i<len; ++i) {
        for(int k=0; k<len; ++k)
            cout << ans[i][k] << " ";
        cout << endl;
    }
    
    
    return 0;
}
