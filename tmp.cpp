/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
        	return head;

        RandomListNode* temp = head;
        while(temp != NULL) {
        	RandomListNode* tp = temp->next;
        	temp->next = new RandomListNode(temp->label);
        	temp->next->next = tp;
        	temp->next->random = temp->random;
        	temp = tp;
        }

        temp = head->next;
        while(temp != NULL) {
        	if(temp->random)
        		temp->random = temp->random->next;
        	if(temp->next)
        		temp = temp->next->next;
        	else
        		temp = NULL;
        }

        

        RandomListNode* head_1 = head;
        RandomListNode* head_2 = head->next;
        RandomListNode* tail_1 = head_1;
        RandomListNode* tail_2 = head_2;
        temp = head_2->next;
        while(temp != NULL) {
        	RandomListNode* nt = temp->next->next;
        	tail_1->next = temp;
        	tail_2->next = temp->next;

        	tail_1 = tail_1->next;
        	tail_2 = tail_2->next;

        	temp = nt;
        }
        tail_1->next = NULL;
        return head_2;

    }
};