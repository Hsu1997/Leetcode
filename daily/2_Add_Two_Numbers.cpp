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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pseudo = new ListNode();
        ListNode *current = pseudo;
        int carry = 0;
        while(l1 && l2){
            current->next = new ListNode( (l1->val + l2->val + carry) % 10 );
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            current = current->next;
        }
        while(l1){
            current->next = new ListNode( (l1->val + carry) % 10 );
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            current = current->next;
        }
        while(l2){
            current->next = new ListNode( (l2->val + carry) % 10 );
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            current = current->next;
        }
        if (carry) current->next = new ListNode(carry);
        return pseudo->next;
    }
};

ListNode* CreateList(vector<int> nums){
    if (nums.size() < 1) return nullptr;
    ListNode *pseude = new ListNode();
    ListNode *current = pseude;
    for (auto i : nums){
        current->next = new ListNode(i);
        current = current->next;
    } 
    return pseude->next;
}

void PrintList(ListNode *root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

int main(){
    vector<int> nums1 = {9,9,9,9,9,9,9};
    vector<int> nums2 = {9,9,9,9};
    ListNode *l1 = CreateList(nums1);
    ListNode *l2 = CreateList(nums2);
    Solution S;
    PrintList(S.addTwoNumbers(l1, l2));
    return 0;
}