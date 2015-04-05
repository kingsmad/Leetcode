/*************************************************************************
    > File Name: 23.Merge k Sorted lists.cpp
    > Author: Archer Liu
    > Mail: maple.km2041@me.com 
    > Created Time: Mon Apr  6 00:23:00 2015
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//template <class T>
//struct list_greater : public binary_function<T, T, bool> {
//    bool operator()(const T& x, const T& y) {
//	return (*mylist)[x]->val > (*mylist)[y]->val;
//    }
//};

struct list_greater {
    bool operator()(ListNode* x, ListNode* y) {
	return x->val > y->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
	// sanity check
	vector<ListNode*>::iterator last = \
		remove(lists.begin(), lists.end(), (ListNode*)0);
	lists.erase(last, lists.end());
	if(lists.empty())
	    return 0;

	ListNode nil(-1);
	ListNode* tail = &nil;

	list_greater greater;
	make_heap(lists.begin(), lists.end(), greater);
	while(!lists.empty()) {
	    pop_heap(lists.begin(), lists.end(), greater); 
	    ListNode* p = lists.back();
	    lists.pop_back();

	    if(p->next) {
		lists.push_back(p->next);
		push_heap(lists.begin(), lists.end(), greater);
	    }

	    tail->next = p;
	    tail = p;
	    tail->next = 0;
	}

	return nil.next;
    }
};

int main(int argc, char** argv) {
    vector<ListNode*> vec;
    vec.push_back(0);

    Solution sol;
    ListNode* p = sol.mergeKLists(vec);    
    
    return 0;
}
