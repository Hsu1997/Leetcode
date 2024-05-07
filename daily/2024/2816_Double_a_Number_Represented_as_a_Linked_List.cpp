#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* create_link_list(vector<int> nodes){
    ListNode* root = new ListNode();
    ListNode* temp = root;
    for (int i : nodes){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return root->next;
}

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* pseudo = new ListNode(0 + ((head->val > 4)? 1 : 0), head);
        while(head) head->val = (head->val * 2 + ((head->next && head->next->val > 4)? 1 : 0)) % 10, head = head->next;
        return (pseudo->val > 0)? pseudo : pseudo->next;
    }
};

int main(){
    vector<int> nodes = {1,8,9};
    // vector<int> nodes = {9,9,9};
    ListNode* head = create_link_list(nodes);
    Solution S;
    head = S.doubleIt(head);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}