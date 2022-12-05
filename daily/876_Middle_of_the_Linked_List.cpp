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
    if (nodes.empty()) return nullptr;
    ListNode* head = new ListNode(nodes[0]);
    ListNode* ptr = head;
    for (int i = 1; i < nodes.size(); i++){
        ptr->next = new ListNode(nodes[i]);
        ptr = ptr->next;
    }
    return head;
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


int main(){
    vector<int> nodes = {1,2,3,4,5};
    // vector<int> nodes = {1,2,3,4,5,6};
    ListNode* head = create_list(nodes);
    Solution S;
    cout << S.middleNode(head)->val << endl;
    return 0;
}