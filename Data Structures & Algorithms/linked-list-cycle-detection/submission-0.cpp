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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> nodes;

        ListNode *ptr=head;

        while(ptr!=NULL){
            if(nodes.find(ptr)!=nodes.end()) return true;
            nodes.insert(ptr);
            ptr=ptr->next;
        }

        return false;
    }
};
