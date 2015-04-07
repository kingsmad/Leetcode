/*************************************************************************
    > File Name: Copy List with Random Pointer.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Thu Apr  2 18:15:33 2015
 ************************************************************************/



 
#include <iostream>
#include <stdlib.h>
using namespace std;

struct RandomListNode {
   int label;
   RandomListNode *next, *random;
   RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
	if(!head)
	    return head;

	RandomListNode* p = head;	
	while(p) {
	    RandomListNode* rep = new RandomListNode(p->label);
	    rep->random = p->random;
	    rep->next = p->next;
	    p->next = rep;
	    p = rep->next;
	}

	p = head;
	while(p) {
	    RandomListNode* q = p->next;
	    if(q->random)
		q->random = q->random->next;
	    p = q->next;
	}

	RandomListNode ans(-1);
	RandomListNode* tail = &ans;
	p = head;
	while(p) {
	    tail->next = p->next;
	    tail = tail->next;
	    p->next = tail->next;
	    tail->next = 0;
	    p = p->next;
	}

	return ans.next;
    }
};


int main(int argc, char** argv) {
    //int len;
    //vector<RandomListNode*> vec(len);
    //for(int i=0; i<len; ++i) {
    //    int t; cin >> t;
    //    vec[i] = new RandomListNode(t);	
    //}
    RandomListNode node(-1);
    node.random = 
}
