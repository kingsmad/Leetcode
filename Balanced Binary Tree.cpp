
#include <iostream>
#include <stack>
struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL)
            return true;
        stack<pair<TreeNode*, bool> > mStack;
        mStack.push(make_pair(root, false));
        while(!mStack.empty()) {
            TreeNode* tmp = mStack.top().first;
            bool used = mStack.top().second;
            mStack.pop();
            
            if(!used) {
                mStack.push(make_pair(tmp, true));
                if(tmp->right != NULL)
                    mStack.push(make_pair(tmp, false));
                if(tmp->left != NULL)
                    mStack.push(make_pair(tmp, false));
            }
            else {
                if(tmp->left != NULL && tmp->right != NULL) {
                    int a = tmp->right->val;
                    int b = tmp->left->val;
                    if(max(a, b) > min(a, b) + 1)
                        return false;
                    else
                        tmp->val = max(tmp->left->val, tmp->right->val) + 1;
                }
                else if (tmp->left == NULL && tmp->right == NULL) {
                    tmp->val = 1;
                }
                else {
                    TreeNode* t = (tmp->left != NULL) ? tmp->left : tmp->right;
                    if(t->left > 2)
                        return false;
                    else {
                        tmp->val = t->val + 1;
                    }
                }
            }
        }
        
        return true; 
    }
};

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;


    return 0;
}