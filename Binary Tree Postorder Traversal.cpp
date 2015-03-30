/*************************************************************************
    > File Name: Binary Tree Postorder Traversal.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Tue Mar 31 00:32:53 2015
 ************************************************************************/

#include<iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) {

    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
	stack<pair<TreeNode*, bool> > istack;
	istack.push(make_pair(root, false));
	vector<int> ans;
	
	while(!istack.empty()) {
	    bool done = istack.top().second;
	    TreeNode* tmp = istack.top().first;
	    istack.pop();
	    if(!done) {
		istack.push(make_pair(tmp, true));
		if(tmp->right)
		    istack.push(make_pair(tmp->right, false));
		if(tmp->left)
		    istack.push(make_pair(tmp->left, false));
	    } else {
		ans.push_back(tmp->val);	
	    }
	}

	return ans;
    }
};
