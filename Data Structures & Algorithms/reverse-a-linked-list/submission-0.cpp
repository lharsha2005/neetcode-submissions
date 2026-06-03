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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;

        ListNode *fast=head->next;
        ListNode *slow=head;

        while(fast!=NULL){
            ListNode *temp=fast;
            if(slow==head){
                slow->next=NULL;
            }
            fast=fast->next;
            temp->next=slow;
            slow=temp;
        }

        return slow;
    }
};
