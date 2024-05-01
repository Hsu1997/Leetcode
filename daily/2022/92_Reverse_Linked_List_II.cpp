#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create_list(vector<int> nums){
    ListNode* pseudo = new ListNode();
    ListNode* temp = pseudo;
    for (auto i : nums){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return pseudo->next;
}

void print_list(ListNode* root){
    while(root != nullptr){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right == left) return head;

        ListNode* pseudo = new ListNode(0, head);
        ListNode* temp = pseudo;
        for (int i = 0; i < left-1; i++) temp = temp->next;

        ListNode* before_left_node = temp;
        temp = temp->next;

        stack<ListNode*> S;
        for (int i = 0; i < right-left+1; i++){
            S.push(temp);
            temp = temp->next;
        }
        ListNode* after_right_node = temp;
        temp = before_left_node;

        while(!S.empty()){
            temp->next = S.top();
            temp = temp->next;
            S.pop();
        }
        temp->next = after_right_node;

        return pseudo->next;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = create_list(nums);
    int left = 2;
    int right = 4;
    Solution S;
    head = S.reverseBetween(head, left, right);
    print_list(head);
    return 0;
}