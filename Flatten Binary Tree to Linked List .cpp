#include <iostream>
#include <vector>
 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        vector<TreeNode*> vec;
        stack<TreeNode*> mStack;
        mStack.push(root);
        
        while(!mStack.empty()) {
            TreeNode* tmp = mStack.top();
            mStack.pop();
            if(tmp->right != NULL)
                mStack.push(tmp->right);
            if(tmp->left != NULL)
                mStack.push(tmp->left);
                
            vec.push_back(tmp);
        }
        
        int vlen = vec.size();
        for(int i=0; i<vlen-1; ++i) {
            vec[i]->right = vec[i+1];
            vec[i]->left = NULL;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}