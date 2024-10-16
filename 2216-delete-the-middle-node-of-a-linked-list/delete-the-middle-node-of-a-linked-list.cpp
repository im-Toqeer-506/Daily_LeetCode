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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL; 
        }
        int l = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            l++;
        }

        int mid = l / 2;
        temp = head;
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }
        ListNode* midNode = temp->next;      
        temp->next = midNode->next;          
        delete midNode;                     
        
        return head;
    }
};
