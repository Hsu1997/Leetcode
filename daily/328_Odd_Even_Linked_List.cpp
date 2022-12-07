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

ListNode* create(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    ListNode* head = new ListNode(nodes[0]);
    ListNode* temp = head;
    for (int i = 1; i < nodes.size(); i++){
        temp->next = new ListNode(nodes[i]);
        temp = temp->next;
    }
    return head;
}

void print_list(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* oddtemp = odd;
        ListNode* eventemp = even;
        ListNode* temp = head->next->next;
        while(temp != nullptr){
            if (temp){
                oddtemp->next = temp;
                oddtemp = oddtemp->next;
                temp = temp->next;
            }
            if (temp){
                eventemp->next = temp;
                eventemp = eventemp->next;
                temp = temp->next;
            }
        }
        oddtemp->next = even;
        eventemp->next = nullptr;
        return head;
    }
};

int main(){
    // vector<int> nodes = {1,2,3,4,5};
    vector<int> nodes = {2,1,3,5,6,4,7};
    ListNode* head = create(nodes);
    // print_list(head);
    Solution S;
    print_list(S.oddEvenList(head));
    return 0;
}