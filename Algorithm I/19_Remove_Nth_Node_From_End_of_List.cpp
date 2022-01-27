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
        ListNode* pointer = head;
        int count = 0;
        while (pointer != NULL){
            pointer = pointer->next;
            count++;
        }
        if (count == 1) return NULL;
        if (count == n) return head->next;
        count -= n + 1;
        pointer = head;
        for (count > 0; count--; ){
            pointer = pointer->next;
        }
        pointer->next = pointer->next->next;
        return head;
    }
};