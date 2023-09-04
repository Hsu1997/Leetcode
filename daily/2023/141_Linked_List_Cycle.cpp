#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* CreateList(vector<int> nums, int pos){
    if (nums.size() == 0) return nullptr;
    ListNode* root = new ListNode(nums[0]);
    ListNode* current = root;
    ListNode* p;
    for (int i = 1; i < nums.size(); i++){
        current->next = new ListNode(nums[i]);
        current = current->next;
        if (i == pos) p = current;
    }
    if (pos == 0) current->next = root;
    if (pos > 0) current->next = p;
    return root;
}

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

int main(){
    vector<int> nodes = {3,2,0,-4};
    int pos = 1;
    // vector<int> nodes = {1,2};
    // int pos = 0;
    // vector<int> nodes = {1};
    // int pos = -1;
    ListNode* root = CreateList(nodes, pos);
    Solution S;
    cout << S.hasCycle(root) << endl;
    return 0;
}