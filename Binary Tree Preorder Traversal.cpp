#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> m_stack;
        m_stack.push(root);
        
        while(!m_stack.empty()) {
            TreeNode* tmp = m_stack.top();
            m_stack.pop();
            result.push_back(tmp->val);
            
            if(tmp->right)
                m_stack.push(tmp->right);
            if(tmp->left)
                m_stack.push(tmp->left);
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
    int len;
    cin >> len;
    
    int num[len];
    TreeNode* tree[len];
    for(int i=0; i<len; ++i) {
        cin >> num[i];
    }
    
    for(int i=0; i<len; ++i) {
        tree[i]= new TreeNode(num[i]);
    }
    for(int i=0; i<len/2; ++i) {
        if(2 * i + 1 < len)
            tree[i]->left = tree[2*i+1];
        if(2 * i + 2 < len)
            tree[i]->right = tree[2*i+2];
    }
    
    Solution s;
    
    vector<int> res(s.preorderTraversal(tree[0]));
    int vsiz = res.size();
    
    for(int i=0; i<vsiz-1; ++i) {
        cout << res[i] << ", ";
    }
    cout << res[vsiz-1] << endl;
    return 0;
}