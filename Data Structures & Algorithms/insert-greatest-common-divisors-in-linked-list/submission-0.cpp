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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr) return head;
        auto curr = head;
        auto next = head->next;
        if(next == nullptr) return head;
        
        while(next != nullptr) {
            ListNode* newNode = new ListNode(gcd(curr->val, next->val));
            curr->next = newNode;
            newNode->next = next;
            curr = next;
            next = next->next;
        }

        return head;
    }
};