// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode*> heap;
        
        for(vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); ++it) {
            if(!*it) {
                lists.erase(it);
                --it;
            } else {
                heap.push_back(*it);
            }
        }
        
        if(!heap.size()) return NULL;
        
        make_heap(heap.begin(), heap.end(), Cmpr());
        ListNode *head = NULL, *prev = NULL;
        
        while(heap.size()) {
            pop_heap(heap.begin(), heap.end(), Cmpr());
            if(!head) head = heap.back();
            if(prev) prev->next = heap.back();
            prev = heap.back();
            if(prev->next) {
                heap.back() = prev->next;
                push_heap(heap.begin(), heap.end(), Cmpr());
            } else {
                heap.pop_back();
            }
        }
        return head;
    }
    
    struct Cmpr {
        bool operator()(ListNode *node1, ListNode *node2) const {
            return (node1->val > node2->val);
        }
    };
};
