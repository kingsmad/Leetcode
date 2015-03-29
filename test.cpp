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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        n = n-m+2;
        ListNode nil(-1);
        nil.next = head;
        ListNode* hd = &nil;
        while(--m > 0) 
            hd = hd->next;
            
        ListNode* fw = hd;
        while(n-- > 0) 
            fw = fw->next;
            
        ListNode* p = hd->next;
        hd->next = NULL;
        ListNode* q = p;
        
        while(p != fw) {
            ListNode* tmp = p;
            p = p->next;
            tmp->next = hd->next;
            hd->next = tmp;
        }
        
        q->next = fw;
        
        return nil.next;
    }
};

int main(int argc, char** argv) {

    int len;
    cin >> len;

    vector<ListNode*> vec;
    for(int i=0, j=4; i<len; ++i) {
        int ti; cin >> ti;
        vec.push_back(new ListNode(ti));
    }
    for(int i=0; i+1<len; ++i) {
        vec[i]->next = vec[i+1];
    }

    Solution sol;
    int m = 0; int n=0;
    printf("please input m\n");
    scanf("%d", &m);

    printf("please input n");
  scanf("%d", &n);
 
    ListNode* hd = sol.reverseBetween(vec[0], m, n);
    while(hd) {
        printf("%d ", hd->val);
        hd = hd->next;
    }

    cout << endl;

}
