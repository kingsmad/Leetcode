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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode nil(-1);
        ListNode* tail = &nil;

        while(true) {
        	int pos = -1;
        	for(int i=0; i<lists.size(); ++i) {
        		if(lists[i] != NULL) {
        			if(pos == -1 || lists[i]->val < lists[pos]->val) {
        				pos = i;
        			}
        		}
        	}

        	if(pos == -1)
        		break;
        	tail->next = lists[pos];
        	tail = lists[pos];
        	lists[pos] = lists[pos]->next;
        }
        
        tail->next = NULL;
        return nil.next;
    }
};

int main(int argc, char const *argv[])
{
	int len;
	cin >> len;
	vector<ListNode*> lists;

	for(int i=0; i<len; ++i) {
		for()
	}
	return 0;
}