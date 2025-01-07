/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
      
      ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0); 
        ListNode* tail = head;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return head->next;
    }

   void mergesort(vector<ListNode*>& lists, int s, int e) {
        if (s >= e) return; 
        int m = s + (e - s) / 2; 
        mergesort(lists, s, m);
        mergesort(lists, m + 1, e);
        lists[s] = merge(lists[s], lists[m + 1]);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr; 
       int n=lists.size();
        mergesort(lists,0,n-1);
        return lists[0];
    }
};
