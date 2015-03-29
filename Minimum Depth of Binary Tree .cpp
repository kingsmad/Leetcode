class Solution {
public:
    int minDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL) {
        	return 0;
        }
        return __minDepth(root);
    }

    int __minDepth(TreeNode* root) {
    	if(!root->left && !root->right)
            return 1;
        else if(!root->left && root->right){
            return __minDepth(root->right) + 1;
        }
        else if(root->left && !root->right)
            return __minDepth(root->left) + 1;
    	else 
    		return min(__minDepth(root->right), __minDepth(root->left)) + 1;
    }
};