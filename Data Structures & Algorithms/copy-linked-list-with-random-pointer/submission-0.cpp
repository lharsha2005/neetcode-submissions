class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> hash;

        Node* ptr = head;

        // Create all copied nodes
        while (ptr) {
            hash[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;

        // Connect next and random pointers
        while (ptr) {
            hash[ptr]->next = hash[ptr->next];
            hash[ptr]->random = hash[ptr->random];
            ptr = ptr->next;
        }

        return hash[head];
    }
};