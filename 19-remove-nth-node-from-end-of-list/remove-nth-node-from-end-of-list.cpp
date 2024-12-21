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
    int sizeCalc(ListNode* head)
    {
        ListNode*temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //khalli linkedList
      if(head==NULL)
      {
        return NULL;
      }
      int size=sizeCalc(head);
      //ager head ko delete karna ho ga 
      if (n == size){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
      ListNode* prev=head;
      for(int i=1;i<(size-n);i++)
      {
        prev=prev->next;
      } 
      ListNode* nodeToDelete = prev->next;
      prev->next=nodeToDelete->next; 
      return head;
    }
};
