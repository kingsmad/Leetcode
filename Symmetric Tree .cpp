/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL)
        	return false;

       	queue<TreeNode*> lQueue, rQueue;

       	lQueue.push(root->left);
       	rQueue.push(root->right);

       	while(!lQueue.empty() && !rQueue.empty()) {
       		TreeNode* ltmp = lQueue.front();
       		TreeNode* rtmp = rQueue.front();
       		lQueue.pop();
       		rQueue.pop();
       		if(ltmp == NULL && rtmp == NULL)
       			continue;
       		else if(ltmp == NULL || rtmp == NULL)
       			return false;
       		if(ltmp->val != rtmp->val)
       			return false;

       		lQueue.push(ltmp->left);
       		lQueue.push(ltmp->right);
       		rQueue.push(rtmp->right);
       		rQueue.push(rtmp->left);
       	}

       	if(lQueue.empty() && rQueue.empty())
       		return true;
       	else
       		return false;
    }
};