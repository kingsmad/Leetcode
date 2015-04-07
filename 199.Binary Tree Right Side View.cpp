/*************************************************************************
    > File Name: 199.Binary Tree Right Side View.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Sun Apr  5 23:21:35 2015
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
	vector<int> ans;
	if(!root)
	    return ans;
	vector<TreeNode*> buf[2];
	int cur = 0;
	int next = 1;
	buf[cur].push_back(root);

	while(!buf[cur].empty()) {
	    ans.push_back(buf[cur].back()->val);
	    int len = buf[cur].size();
	    for(int i=0; i<len; ++i) {
		if(buf[cur][i]->left)
		    buf[next].push_back(buf[cur][i]->left);
		if(buf[cur][i]->right)
		    buf[next].push_back(buf[cur][i]->right);
	    }
	    buf[cur].clear();
	    cur = !cur;
	    next = !next;
	}

	return ans;
    }
};

int main(int argc, char** argv) {

}
