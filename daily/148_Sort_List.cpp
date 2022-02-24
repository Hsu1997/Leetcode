#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // empty or only one node than return
        if (!head || !head->next) return head;
        ListNode* mid = split_two_list(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        head = merge(left, right);
        return head;
    }

    ListNode* split_two_list(ListNode* head){
        ListNode emptyhead = ListNode(0, head);
        ListNode* premid = &emptyhead;
        while (head && head->next){
            premid = premid->next;
            head = head->next->next;
        }
        ListNode* mid = premid->next;
        premid->next = nullptr;
        return mid;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode emptyhead = ListNode(0);
        ListNode* ptr = &emptyhead;
        while(left && right){
            if (left->val > right->val){
                ptr->next = right;
                right = right->next;
            }
            else{
                ptr->next = left;
                left = left->next;
            }
            ptr = ptr->next;
        }
        if (left) ptr->next = left;
        if (right) ptr->next = right;

        return emptyhead.next;
    }
};

int main(){
    int list[] = {4,2,1,3};
    int len = sizeof(list)/sizeof(list[0]);

    ListNode* head = new ListNode();
    ListNode* current = head;
    for (int i = 0; i < len; i++){
        current->next = new ListNode(list[i]);
        current = current->next;
    }
    head = head->next;
    PrintList(head);
    
    Solution S;
    PrintList(S.sortList(head));

    return 0;
}