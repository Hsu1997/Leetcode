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

ListNode* CreateLinkList(vector<int>& nums){
    ListNode *pseudo = new ListNode();
    ListNode *current = pseudo;
    for (auto i : nums){
        current->next = new ListNode(i);
        current = current->next;
    }
    return pseudo->next;
}

void PrintLinkList(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* pseudo = new ListNode(0, head);
        ListNode *ptr1, *ptr2, *now;
        now = pseudo;
        for (int i = 0; i < k; i++) now = now->next;
        ptr1 = now;
        ptr2 = pseudo;
        while(now){
            now = now->next;
            ptr2 = ptr2->next;
        }
        swap(ptr1->val, ptr2->val);
        return head;
    }
};

int main(){
    // vector<int> nums = {7,9,6,6,7,8,3,0,9,5};
    vector<int> nums = {1,2};
    int k = 2;
    Solution S;
    ListNode* head = CreateLinkList(nums);
    head = S.swapNodes(head, k);
    PrintLinkList(head);


}