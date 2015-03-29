#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * Definition for binary tree*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = num.size();
        if(len < 1)
            return NULL;
            
        vector<TreeNode*> nodes(len);
        for(int i=0; i<len; ++i) 
            nodes[i] = new TreeNode(num[i]);
        
        stack<pair<int, int> > mStack;
        mStack.push(make_pair(0, len));
        
        while(!mStack.empty()) {
            int first = mStack.top().first;
            int last = mStack.top().second;
            mStack.pop();
            
            int cur = (first + last) >> 1;
            TreeNode* tmp = nodes[cur];
            if(cur != first)
                tmp->left = nodes[(cur+first)>>1];
            if(cur != last-1)
                tmp->right = nodes[(cur+1+last)>>1];
            
            if(cur - first > 1)    
                mStack.push(make_pair(first, cur));
            if(last - cur > 2)
                mStack.push(make_pair(cur+1, last));
        }
        
        return nodes[len>>1];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}



/*

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num, int p, int r)
    {
        if(p > r){
            return NULL;
        }
        if(p == r){
            return new TreeNode(num[p]);
        }
        int q = (p+r)/2;
        TreeNode *root = new TreeNode(num[q]);
        root->left = sortedArrayToBST(num, p, q-1);
        root->right = sortedArrayToBST(num, q+1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return sortedArrayToBST(num, 0, num.size()-1);
    }
};

*/
