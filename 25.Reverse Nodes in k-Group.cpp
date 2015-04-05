/*************************************************************************
    > File Name: 25.Reverse Nodes in k-Group.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Sun Apr  5 23:33:30 2015
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
	ListNode nil(-1);
	nil.next = head;
	ListNode* first = &nil;

	while(first) {
	    ListNode* last = first->next;
	    int c = k;
	    while(last && c > 0 ) {
		last = last->next;
		--c;
	    }
	    if(c > 0)
		break;
	    ListNode* p = first->next;
	    ListNode* riddle = p;
	    first->next = last;
	    while(p != last) {
		ListNode* tmp = p->next;
		p->next = first->next;
		first->next = p;
		p = tmp;
	    }
	    first = riddle; 
	}

	return nil.next;
    }
};

int main(int argc, char** argv) {
    int len, k;
    cin >> len >> k;
    
    vector<ListNode*> nodes;
    for(int i=0; i<len; ++i) {
	int t;
	cin >> t;
	nodes.push_back(new ListNode(t));
    }

    for(int i=0; i+1<len; ++i) {
	nodes[i]->next = nodes[i+1];
    }
    
    Solution sol;
    ListNode* new_nodes = sol.reverseKGroup(nodes[0], k);

    for(ListNode* p=new_nodes; p; p=p->next)
	printf("%d ", p->val);

    return 0;
}
