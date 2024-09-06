#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create_list(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    ListNode* root = new ListNode(nodes[0]);
    ListNode* temp = root;
    for (int i = 1; i < nodes.size(); i++){
        temp->next = new ListNode(nodes[i]);
        temp = temp->next;
    }
    return root;
}

void print_list(ListNode* root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for (int i : nums) s.insert(i);
        ListNode* pseudo = new ListNode(0, head);
        ListNode* temp = pseudo;
        ListNode* ptr = head;
        while(ptr != nullptr){
            if (s.find(ptr->val) == s.end()){
                temp->next = ptr;
                temp = temp->next;
            }
            ptr = ptr->next;
        }
        temp->next = nullptr;
        return pseudo->next;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    vector<int> nodes = {1,2,3,4,5};
    // vector<int> nums = {1};
    // vector<int> nodes = {1,2,1,2,1,2};
    // vector<int> nums = {5};
    // vector<int> nodes = {1,2,3,4};
    ListNode* head = create_list(nodes);
    Solution S;
    ListNode* ans = S.modifiedList(nums, head);
    print_list(ans);
    return 0;
}