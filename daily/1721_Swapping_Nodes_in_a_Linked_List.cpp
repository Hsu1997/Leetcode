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

// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         int count = 0;
//         ListNode* C = head;
//         while(C != nullptr){
//             count++;
//             C = C->next;
//         }
//         if (count == 0 || (count % 2 == 1 && k == count / 2 + 1)) return head;
//         else if (count == 2){
//             ListNode* second = head->next;
//             second->next = head;
//             head->next = nullptr;
//             return second;
//         }
//         else if (k > count / 2) k = (count/2)+(count%2)-k%(count/2)+1;

//         ListNode* pseudo = new ListNode(0, head);
//         ListNode* first = pseudo;
//         ListNode* find = head;
        
//         for (int i = 0; i < k - 1; i++){
//             find = find->next;
//             first = first->next;
//         }

//         ListNode* k_th = find;
//         find = find->next;

//         ListNode* k2_th = head;
//         ListNode* second = pseudo;

//         while(find != nullptr){
//             find = find->next;
//             k2_th = k2_th->next;
//             second = second->next;
//         }
//         first->next = k2_th;
//         first = k2_th->next;
//         if (k_th != second){
//             k2_th->next = k_th->next;
//             second->next = k_th;
//         }
//         else{
//             k2_th->next = k_th;
//             k_th->next = first;
//         }
//         k_th->next = first;
//         return head;
//     }
// };

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