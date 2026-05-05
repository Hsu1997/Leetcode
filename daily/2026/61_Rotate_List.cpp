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
    ListNode* pseudo = new ListNode();
    ListNode* ptr = pseudo;
    for (int i : nodes){
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    return pseudo->next;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* ptr = head;
        int n = 0;
        while(ptr->next){
            n++;
            ptr = ptr->next;
        }
        n++;
        ptr->next = head;
        int c = n - 1 - (k % n);
        ptr = head;
        while(c--){
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = nullptr;
        return head;
    }
};

int main(){
    vector<int> nodes = {1,2,3,4,5};
    int k = 2;
    // vector<int> nodes = {0,1,2};
    // int k = 4;
    // vector<int> nodes = {};
    // int k = 0;
    ListNode* head = createList(nodes);
    Solution S;
    head = S.rotateRight(head, k);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}