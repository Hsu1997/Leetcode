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
    return;
}

// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         vector<int> nodes;
//         ListNode* temp = head;
//         while(temp != nullptr){
//             nodes.push_back(temp->val);
//             temp = temp->next;
//         }
//         // for (auto i : nodes) cout << i << " ";
//         // cout << endl;
//         int n = nodes.size();
//         ListNode* n1 = head;
//         ListNode* n2 = head;
//         for (int i = 0; i < k-1; i++) n1 = n1->next;
//         for (int i = 0; i < n-k; i++) n2 = n2->next;
//         swap(n1->val, n2->val);
//         return head;
//     }
// };

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* pseudo = new ListNode(0, head);
        ListNode* now = pseudo;
        ListNode* n1 = pseudo;
        ListNode* n2 = pseudo;
        for (int i = 0; i < k; i++) now = now->next;
        n1 = now;
        while(now){
            now = now->next;
            n2 = n2->next;
        }
        swap(n1->val, n2->val);
        return head;
    }
};

int main(){
    // vector<int> nodes=  {1,2,3,4,5};
    // int k = 2;
    vector<int> nodes=  {7,9,6,6,7,8,3,0,9,5};
    int k = 5;
    ListNode* head = create_list(nodes);
    Solution S;
    head = S.swapNodes(head, k);
    print_list(head);
    return 0;
}