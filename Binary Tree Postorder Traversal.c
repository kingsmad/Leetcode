#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/* This code has not pass test yet*/
#define BUF_SIZ 256
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    struct TreeNode** stack = (struct TreeNode**) malloc(sizeof(void*)*BUF_SIZ);
    char* flag = (char*)malloc(sizeof(char)*BUF_SIZ);

    int* ans = (int*) malloc(sizeof(int) * BUF_SIZ);
    *returnSize = 0;
    int sp = 0;
    if (root) {
        stack[sp++] = root;
        flag[0] = 0;
    }

    while(sp > 0) {
        char done = flag[sp-1];
        struct TreeNode* tmp = stack[sp-1];
        --sp;

        if(!done) {
            stack[sp] = tmp;
            flag[sp] = 1;
            ++sp;
            if(tmp->right) {
                stack[sp] = tmp->right;
                flag[sp] = 0;
                ++sp;
            }
            if(tmp->left) {
                stack[sp] = tmp->left;
                flag[sp] = 0;
                ++sp;
            }
        } else {
            ans[*returnSize++] = tmp->val;
        }
    }

    return ans;
}


int main(int argc, char** argv) {
    int len;
    scanf("%d", &len);
    struct treenode* buf[len];
    memset(buf, 0, sizeof(buf));
    
    for(int i=0; i<len; ++i) {
	char v;
	scanf("\n %c", &v);    
	if(v == '#') 
	    continue;
	buf[i] = (struct treenode*) malloc(sizeof(struct treenode));
	buf[i]->val = v - '0';
	buf[i]->left = buf[i]->right = 0;
    }
    for(int i=0; i<len; ++i) {
	if (!buf[i])
	    continue;
	if (2*i+1 < len)
	    buf[i]->left = buf[2*i+1];
	if(2*i+2 < len)
	    buf[i]->right = buf[2*i+2];
    }

    int siz;
    int* ptr = postorderTraversal(buf[0], &siz); 
    
    for(int i=0; i<siz; ++i) {
	printf("%c ", ptr[i]);
    }

    return 0;
}
