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

ListNode* create_list(vector<int> nodes){
    ListNode* pseudo = new ListNode();
    ListNode* temp = pseudo;
    for (auto i : nodes){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return pseudo->next;
}

void print_list(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pseudo = new ListNode(0, head);
        ListNode* pre = pseudo;
        ListNode* now = head;
        while(now && now->next){
            pre->next = pre->next->next;
            now->next = now->next->next;
            pre->next->next = now;
            pre = pre->next->next;
            now = now->next;
        }
        return pseudo->next;
    }
};

int main(){
    // vector<int> nodes = {1,2,3,4};
    vector<int> nodes = {};
    ListNode* head = create_list(nodes);
    Solution S;
    head = S.swapPairs(head);
    print_list(head);
    return 0;
}