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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       	if(!p && !q)
       		return true;
       	if(!p || !q || p->val != q->val)
       		return false;
       	if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
       		return true;
       	else 
       		return false;
    }
};