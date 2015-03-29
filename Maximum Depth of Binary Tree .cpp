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
    int maxDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL) {
        	return 0;
        }
        return __maxDepth(root);
    }

    int __maxDepth(TreeNode* root) {
    	if(root->left == NULL && root->right == NULL)
    		return 1;
    	else if (root->left == NULL && root->right)
    		return __maxDepth(root->right) + 1;
    	else if (root->right == NULL && root->left)
    		return __maxDepth(root->left) + 1;
    	else 
    		return max(__maxDepth(root->right), __maxDepth(root->left)) + 1;
    }
};