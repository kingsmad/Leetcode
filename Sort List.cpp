#include <vector>
#include <iostream>
using namespace std;

class ListNode {
public:
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

bool g_listNode_less(ListNode* p1, ListNode* p2) {
    return p1->val < p2->val;
}

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL)
            return head;
            
        vector<ListNode*> buf;
        for(ListNode* p=head; p!=NULL; p=p->next)
            buf.push_back(p);
        sort(buf.begin(), buf.end(), g_listNode_less);
        
        int tz = buf.size() - 1;
        for(int i=0; i<tz; ++i)
            buf[i]->next = buf[i+1];
        buf[tz]->next = NULL;
               
        return buf[0];
    }
};

int main(int argc, char const *argv[])
{
    int len;
    cin >> len;

    vector<ListNode*> nodes(len);
    for(int i=0; i<len; ++i) {
        int tmp ;
        cin >> tmp;
        nodes[i] = new ListNode(tmp);
    }

    for(int i=0; i<len-1; ++i) {
        nodes[i]->next = nodes[i+1];
    }

    cout << endl;
    for(ListNode* t=nodes[0]; t!=NULL; t=t->next)
        cout << t->val << " ";

    cout << endl;

    Solution s;
    ListNode* ans = s.sortList(nodes[0]);


    for(; ans!=NULL; ans=ans->next)
        cout << ans->val << " ";
    cout << endl;
    return 0;
}