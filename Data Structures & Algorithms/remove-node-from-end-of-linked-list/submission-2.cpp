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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        for(ListNode* i = head; i != nullptr; i=i->next) {
            len++;
        }
        if(len==1) return nullptr;
        if(len - n == 0) return head->next;
        ListNode* rem = head;
        for(int i = 0; i < len - n - 1; i++) {
            rem = rem->next;
        }
        rem->next = rem->next->next;
        return head;
    }
};
