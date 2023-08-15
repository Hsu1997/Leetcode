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

ListNode* create_link_list(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    ListNode* head = new ListNode(nodes[0]);
    ListNode* temp = head;
    for (int i = 1; i < nodes.size(); i++){
        temp->next = new ListNode(nodes[i]);
        temp = temp->next;
    }
    return head;
}

void print_link_list(ListNode* root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_than = new ListNode();
        ListNode* greater_or_equal = new ListNode();
        ListNode* temp_less = less_than;
        ListNode* temp_greater = greater_or_equal;
        ListNode* temp = head;
        while(temp){
            if (temp->val < x){
                temp_less->next = temp;
                temp_less = temp_less->next;
            }
            else{
                temp_greater->next = temp;
                temp_greater = temp_greater->next;
            }
            temp = temp->next;
        }
        temp_greater->next = nullptr;
        temp_less->next = greater_or_equal->next;
        return less_than->next;
    }
};

int main(){
    vector<int> nodes = {1,4,3,2,5,2};
    int x = 3;
    ListNode* root = create_link_list(nodes);
    // print_link_list(root);
    Solution S;
    print_link_list(S.partition(root, x));
    return 0;
}