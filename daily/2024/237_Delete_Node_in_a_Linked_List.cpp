#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_link_list(vector<int> nodes){
    ListNode* root;
    ListNode* temp = root;
    for (int i : nodes) temp->next = new ListNode(i), temp = temp->next;
    return root->next;
}

ListNode* find_specific_number(ListNode* root, int x){
    while(root && root->val != x) root = root->next;
    if (root) return root;
    else return nullptr;
}

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main(){
    vector<int> nodes = {4,5,1,9};
    int node = 5;
    // int node = 1;
    ListNode* root = create_link_list(nodes);
    ListNode* temp = root;
    while(temp) cout << temp->val << " ", temp = temp->next;
    cout << endl;
    ListNode* del = find_specific_number(root, node);
    Solution S;
    S.deleteNode(del);
    temp = root;
    while(temp) cout << temp->val << " ", temp = temp->next;
    cout << endl;
    return 0;
}