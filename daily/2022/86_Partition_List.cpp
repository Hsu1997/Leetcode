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
    ListNode* partition(ListNode* head, int x) {
        ListNode* pseudo1 = new ListNode(0);
        ListNode* pseudo2 = new ListNode(0);
        ListNode* less = pseudo1;
        ListNode* equal_or_greater = pseudo2;
        while(head != nullptr){
            // cout << head->val << " ";
            if (head->val < x) less->next = head, less = less->next;
            else equal_or_greater->next = head, equal_or_greater = equal_or_greater->next;
            head = head->next;
            // print_list(pseudo1->next);
            // print_list(pseudo2->next);
            // cout << endl;
        }
        if (less == pseudo1) return pseudo2->next;
        less->next = pseudo2->next;
        equal_or_greater->next = nullptr;

        return pseudo1->next;
    }
};

int main(){
    int x = 3;
    vector<int> node = {1,4,3,2,5,2};
    // int x = 2;
    // vector<int> node = {2,1};
    ListNode* head = create_list(node);
    Solution S;
    head = S.partition(head, x);
    print_list(head);
    return 0;
}