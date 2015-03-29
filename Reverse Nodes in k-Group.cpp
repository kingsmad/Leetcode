#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode nil(-1);
        nil.next = head;
        for(ListNode* p=&nil; p!=NULL; ) {
            /*first 与last还是抓住要反转的区间本身
             header 由p来扮演
             实际在操作中，重要的就是p(也是hd), first, last三个位置*/
            ListNode* first = p->next;
            ListNode* last = first;
            int cnt = k;
            while(cnt > 0 && last!=NULL) {
                last = last->next;
                --cnt;
            }
            if(cnt > 0)
                break;
            for(ListNode* pv=first; pv!=last;) {
                ListNode* tmp = pv->next;
                pv->next = p->next;
                p->next = pv;
                pv = tmp;
            }
            first->next = last;
            p = first;
        }
        
        return nil.next;
    }
};


int main(int argc, char const *argv[])
{
    int len;
    cin >> len;
    int k;
    cin >> k;
    
    vector<int> nums(len);
    for(int i=0; i<len; ++i) {
        cin >> nums[i];
    }
    
    vector<ListNode*> nodes(len);
    for(int i=0; i<len; ++i) {
        nodes[i] = new ListNode(nums[i]);
    }
    
    for(int i=0; i<len-1; ++i) {
        nodes[i]->next = nodes[i+1];
    }
    
    Solution sol;
    ListNode* ans = sol.reverseKGroup(nodes[0], k);
    
    for(ListNode* p=ans; p!=NULL; p=p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    
    return 0;
}