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

ListNode* create_list(vector<int> node){
    if (node.empty()) return 0;
    ListNode* head = new ListNode(node[0]);
    ListNode* temp = head;
    for (int i = 1; i < node.size(); i++){
        temp->next = new ListNode(node[i]);
        temp = temp->next;
    }
    return head;
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* temp = head;
        int size = 0;
        while(temp){
            size++;
            temp = temp->next;
        }
        // cout << size << endl;
        temp = head;
        for (int i = 0; i < size/2-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};

int main(){
    vector<int> node = {1,3,4,7,1,2,6};
    // vector<int> node = {1,2,3,4};
    // vector<int> node = {2,1};
    // vector<int> node = {};
    ListNode* head = create_list(node);
    // print_list(head);
    Solution S;
    S.deleteMiddle(head);
    print_list(head);
    return 0;
}