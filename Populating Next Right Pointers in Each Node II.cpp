/*************************************************************************
    > File Name: Populating Next Right Pointers in Each Node II.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  2 22:23:10 2015
 ************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
	if(!root)
	    return;
	vector<TreeLinkNode*> buf[2];
	int cur = 0;
	int next = 1;
	root->next = NULL;
	buf[cur].push_back(root);
	
	while(!buf[cur].empty()) {
	    int len = buf[cur].size();
	    for(int i=0; i<len; ++i) {
		if(buf[cur][i]->left)
		    buf[next].push_back(buf[cur][i]->left);
		if(buf[cur][i]->right)
		    buf[next].push_back(buf[cur][i]->right);
	    }

	    if(buf[next].empty())
		return;

	    len = buf[next].size();
	    for(int i=0; i+1<len; ++i) {
		buf[next][i]->next = buf[next][i+1]; 
	    }
	    buf[next][len-1]->next = 0;

	    buf[cur].clear();
	    cur = !cur;
	    next = !next;
	}

	return; 
    }
};

int main(int argc, char** argv) {

}
