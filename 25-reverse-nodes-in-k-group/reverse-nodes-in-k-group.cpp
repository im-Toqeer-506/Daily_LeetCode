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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;
        ListNode* temp = head;

        int cnt = 0;
        while (cnt < k) {
            if (temp == NULL) {
                return head;
            } else {
                cnt++;
                temp = temp->next;
            }
        }
        ListNode* PreNode = reverseKGroup(temp, k);
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = PreNode;
            PreNode = temp;
            temp = next;
            cnt++;
        }
        return PreNode;
    }
};