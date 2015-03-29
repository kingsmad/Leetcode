/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* pi = head;
        ListNode* po = head;
        while(pi && po) {
        	pi = pi->next;
        	if(!po->next)
        		return false;
        	else 
        		po = po->next->next;
        	if(pi == po)
        		return true;
        }
        return false;
    }
};

// #include <iostream>
// int main(int argc, char* argv[]) {
// 	int a = 0xffffffff;
// 	std::cout << a << std::endl;
// }