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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        //lifo
        stack<int>stk;

        while(temp!=nullptr)
        {
            stk.push(temp->val);
            temp=temp->next;
        }
        while(head!=nullptr)
        {
            int ele=stk.top();
            stk.pop();
            if(head->val!=ele)return false;
           head=head->next;
        }
        return true;
    }
};