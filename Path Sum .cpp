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
    bool hasPathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL)
        	return false;
        else
        	return __hasPathSum(root, sum);
    }

    bool __hasPathSum(TreeNode* root, int sum) {
    	if(!root->left && !root->right) {
    		if(sum == root->val)
    			return true;
    		else
    			return false;
    	}
    	else {
    		if(root->left && __hasPathSum(root->left, sum - root->val))
    			return true;
    		if(root->right && __hasPathSum(root->right, sum - root->val))
    			return true;
    	}
    }
};