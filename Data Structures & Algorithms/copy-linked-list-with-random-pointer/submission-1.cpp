/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        unordered_map<Node*, Node*> n;

        Node* newHead = new Node(head->val);
        n[head] = newHead;

        Node* curr = newHead; 
        for(Node* i = head->next; i != nullptr; i = i->next) {
            Node* newNode = new Node(i->val);
            curr->next = newNode;
            n[i] = newNode;
            curr = curr->next;
        }

        curr = newHead;
        for(Node* i = head; i != nullptr; i = i->next) {
            if (i->random)
                curr->random = n[i->random];
            else
                curr->random = nullptr;
            curr = curr->next;
        }
        return newHead;
    }
};
