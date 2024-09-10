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

ListNode* create_list(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    ListNode* head = new ListNode(nodes[0]);
    ListNode* curr = head;
    for (int i = 1; i < nodes.size(); i++){
        curr->next = new ListNode(nodes[i]);
        curr = curr->next;
    }
    return head;
}

void print_list(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    int GCD(int a, int b){
        if (a % b == 0) return b;
        return GCD(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr){
            prev->next = new ListNode(GCD(prev->val, curr->val));
            prev->next->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

int main(){
    vector<int> nodes = {18,6,10,3};
    // vector<int> nodes = {7};
    ListNode* head = create_list(nodes);
    Solution S;
    S.insertGreatestCommonDivisors(head);
    print_list(head);
    return 0;
}