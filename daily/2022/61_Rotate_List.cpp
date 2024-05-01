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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int size = 1;
        ListNode* current = head;
        while(current->next){
            size++;
            current = current->next;
        }
        if (size == 1) return head;
        k = k % size;
        if (k == 0) return head;
        size -= k; // size >= 1
        current->next = head;
        for (int i = 0; i < size; i++){
            current = current->next;
        }
        head = current->next;
        current->next = nullptr;
        return head;
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
    vector<int> nums = {0,1,2};
    ListNode* root = CreateList(nums);
    int k = 4;
    Solution S;
    PrintList(S.rotateRight(root, k));
    return 0;
}