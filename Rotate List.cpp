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
    ListNode *rotateRight(ListNode *head, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || k < 1)
            return head;
            
        ListNode nil(-1);
        nil.next = head;
        
        ListNode* tmp = &nil;
        ListNode* first = tmp;
        ++k;
        while(tmp->next != NULL && --k > 0)
            tmp = tmp->next;
        if (tmp->next == NULL && k > 0) {
            first = head->next;
            head->next = NULL;
            while(first != NULL) {
                ListNode* t = nil.next;
                ListNode* p = first->next;
                nil.next = first;
                first->next = t;
                first = p;
            }    
        }
        
        else  {  
            while(tmp->next != NULL) {
                first = first->next ;
                tmp = tmp->next;
            }
            
            tmp->next = head;
            nil.next = first->next;
            first->next = NULL;
            
        }
        
        return nil.next;
    }
};


int main(int argc, char const *argv[])
{
    int len ;
    cin >> len;
    int r;
    cin >> r;

    int num[len];
    ListNode* nodes[len];
    for(int i=0; i<len; ++i) {
        cin >> num[i];
        nodes[i] = new ListNode(num[i]); 
    }
    for(int i=0; i<len-1; ++i) {
        nodes[i]->next = nodes[i+1];
    }

    nodes[len-1]->next = NULL;

    for(ListNode* p=nodes[0]; p!=NULL; p=p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    Solution s;
    s.rotateRight(nodes[0], r);

    for(ListNode* p=nodes[0]; p!=NULL; p=p->next) {
        cout << p->val << " ";
    }
    cout << endl;

    return 0;
}