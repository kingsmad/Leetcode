/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution I;
// class Solution {
// public:
//     void reorderList(ListNode *head) {
//         // IMPORTANT: Please reset any member data you declared, as
//         // the same Solution instance will be reused for each test case.
//         if(head == NULL || head->next == NULL)
//             return;
        
//         ListNode* tail1 = head;
//         ListNode* tail2 = head;
        
//         for(; tail2->next != NULL; ) {
//             tail1 = tail1->next;
//             //two steps
//             tail2 = tail2->next;
//             if(tail2->next)
//                 tail2 = tail2->next;
//         }
        
//         ListNode* head1 = head;
//         ListNode* head2 = tail1->next;
//         tail1->next = NULL;
        
//         ListNode nil_node(-1);
//         ListNode* nil_hd = &nil_node;
//         for(ListNode* pv = head2; pv != NULL; ) {
//             ListNode* next = pv->next;
//             pv->next = nil_hd->next;
//             nil_hd->next = pv;
//             pv = next;
//         }//reverse the head2List
//         head2 = nil_node.next;
        
//         nil_node.next = NULL;
//         ListNode* tail = &nil_node;
//         while(head1 != NULL && head2 != NULL) {
//             ListNode* tmp = head1->next;
//             tail->next = head1;
//             head1->next = head2;
            
//             tail = head2;
//             head2 = head2->next;
//             head1 = tmp;
//         }
        
//         if(head1 != NULL) {
//             tail->next = head1;
//         }
//     }
// };
/*
    合并链表，反序链表等等，最好设定一个新的空节点作为起始节点。方便而且不容易出错
*/

// Solution II
class Solution {
public:
    void reorderList(ListNode *head) {
        unordered_map<int, ListNode*> imap;
        int i = 0;
        for(ListNode* p=head; p; p=p->next)
            imap.insert(make_pair(i++, p));
            
        ListNode nil(-1);
        ListNode* tail = &nil;
        int k = 0;
        --i;
        
        while(k < i) {
            tail->next = imap[k];
            tail->next->next = imap[i];
            ++k; --i;
            tail = tail->next->next;
        }
        if(k == i) {
            tail->next = imap[i];
            tail = tail->next;
        }
        tail->next = NULL;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    // ifstream in("/Developer/dat.txt");
    // cin.rdbuf(in.rdbuf);
    int len;
    cin >> len;
    int num[len];
    ListNode* nodes[len];
    
    for(int i=0; i<len; ++i) {
        cin >> num[i];
    }
    
    nodes[len-1] = new ListNode(num[len-1]);
    for(int i=len-2; i>-1; --i) {
        nodes[i] = new ListNode(num[i]);
        nodes[i]->next = nodes[i+1];
    }
    
    Solution s;
    s.reorderList(nodes[0]);
    
    ListNode* tmp = nodes[0];
    while(tmp != NULL && tmp->next != NULL) {
        cout << tmp->val << ", ";
        tmp = tmp->next;
    }
    cout << tmp->val << endl;
    
    return 0;
}