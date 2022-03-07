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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        // ListNode* root = (list1->val > list2->val)?  list2 : list1;
        ListNode* pseudo_root = new ListNode();
        ListNode* current = pseudo_root;
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val > list2->val){
                current->next = list2;
                list2 = list2->next;
            }
            else{
                current->next = list1;
                list1 = list1->next;
            }
            current = current->next;
        }
        if (list1 != nullptr) current->next = list1;
        if (list2 != nullptr) current->next = list2;
        return pseudo_root->next;
    }
};

ListNode* CreateList(vector<int> nums){
    if (nums.size() == 0) return nullptr;
    ListNode* root = new ListNode(nums.at(0));
    ListNode* current = root;
    for (vector<int>::iterator i = ++nums.begin(); i != nums.end(); i++){
        current->next = new ListNode(*i);
        current = current->next;
    }
    return root;
}

void PrintList(ListNode* root){
    while (root != nullptr){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

int main(){
    vector<int> nums1 = {1,2,4};
    vector<int> nums2 = {1,3,4};
    ListNode* root1 = CreateList(nums1);
    ListNode* root2 = CreateList(nums2);
    Solution S;
    ListNode* root;
    root = S.mergeTwoLists(root1, root2);
    PrintList(root);
    return 0;
}