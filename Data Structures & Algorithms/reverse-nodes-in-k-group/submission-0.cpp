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
    bool check(ListNode *ptr,int k){
        while(k>0 && ptr){
            ptr=ptr->next;
            k--;
        }

        if(k>0){
            return false;
        }

        return true;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr=head;
        ListNode *prev;
        while(check(ptr,k)){
            ListNode *next=ptr;
            for(int i=0;i<k;i++){
                next=next->next;
            }

            ListNode *fast=ptr,*curr=ptr,*slow=next;
            bool ishead=false;
            if(ptr==head)   ishead=true;
            for(int i=0;i<k;i++){
                fast=fast->next;
                curr->next=slow;
                slow=curr;
                curr=fast;
            }
            if(ishead){  
                head=slow;
                prev=ptr;
            }
            else{
                prev->next=slow;
                prev=ptr;
            }
            ptr=curr;
        }

        return head;
    }
};
