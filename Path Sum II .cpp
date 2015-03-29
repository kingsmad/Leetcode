
 // Definition for binary tree
 
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
    // vector<vector<int> > pathSum(TreeNode *root, int sum) {
    //     // IMPORTANT: Please reset any member data you declared, as
    //     // the same Solution instance will be reused for each test case.
    //     int total = 0;
    //     vector<vector<int> > result;
    //     vector<int> path;
    //     if(root == NULL)
    //     	return result;
        
    //     std::stack<pair<TreeNode*, int> > stack;
    //     stack.push(make_pair(root, 0));
	  

    //     while(!stack.empty()) {
    //     	TreeNode* tmp = stack.top().first;
    //     	int used = stack.top().second;
    //     	stack.pop();

    //     	if(!used) {
    //     		if(tmp->val + total <= sum) {
    //                 stack.push(make_pair(tmp, 1));
    //                 total += tmp->val;
    //                 path.push_back(tmp->val);
                    
    //     			if(tmp->right)
    //     				stack.push(make_pair(tmp->right, 0));

    //     			if(tmp->right)
    //     				stack.push(make_pair(tmp->left, 0));
    //     		} 
    //     	} 

    //     	else {
    //     		if(tmp->left == NULL && tmp->right == NULL) {
    //     			result.push_back(vector<int>(path));
    //     		} 	
    //     		total -= tmp->val;
    //     		path.pop_back();
    //     	}
    //     }

    //     return result;
    // }
};

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL)
            return false;
        else {
            vector<vector<int> > result;
            vector<int> path;
            __hasPathSum(root, sum, &result, &path);
            return result;
        }
    }

    void __hasPathSum(TreeNode* root, int sum, vector<vector<int> >& result, vector<int>& path) {
        if(!root->left && !root->right) {
            if(sum == root->val){

            }
            else
                return false;
        }
        else {
            path.push_back(root->val);
            if(root->left && __hasPathSum(root->left, sum - root->val))
                return true;
            if(root->right && __hasPathSum(root->right, sum - root->val))
                return true;
        }
    }
};