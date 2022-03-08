#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return 1;
        }
        return 0;
    }
};

ListNode* CreateList(vector<int> nums){
    if (nums.size() == 0) return nullptr;
    ListNode* root = new ListNode(nums[0]);
    ListNode* current = root;
    for (int i = 1; i < nums.size(); i++){
        ListNode* next = new ListNode(nums[i]);
        current->next = next;
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
    vector<int> nums = {3,2,0,-4};
    ListNode* root;
    root = CreateList(nums);
    // PrintList(root);
    // root->next->next->next->next = root;
    Solution S;
    cout << S.hasCycle(root) << endl;
    return 0;
}