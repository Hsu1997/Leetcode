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

ListNode* createList(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    ListNode* head = new ListNode(nodes[0]);
    ListNode* ptr = head;
    int n = nodes.size();
    for (int i = 1; i < n; i++){
        ptr->next = new ListNode(nodes[i]);
        ptr = ptr->next;
    }
    return head;
}

void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* pseudo = new ListNode(0, head);
        ListNode* ptr = pseudo;
        int n = 0;
        while(ptr->next){
            n++;
            ptr = ptr->next;
        }
        ptr = pseudo;
        n /= 2;
        while(n){
            n--;
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return pseudo->next;
    }
};

int main(){
    vector<int> nodes = {1,3,4,7,1,2,6};
    // vector<int> nodes = {1,2,3,4};
    // vector<int> nodes = {2,1};
    ListNode* head = createList(nodes);
    Solution S;
    printList(S.deleteMiddle(head));
    return 0;
}