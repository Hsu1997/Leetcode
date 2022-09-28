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

ListNode* create(vector<int> list){
    if (list.empty()) return nullptr;

    ListNode* root = new ListNode(list[0]);
    ListNode* prev = root;
    for (int i = 1; i < list.size(); i++){
        prev->next = new ListNode(list[i]);
        prev = prev->next;
    }
    return root;
}

void print_list_node(ListNode* root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pointer = head;
        int count = 0;
        while (pointer != NULL){
            pointer = pointer->next;
            count++;
        }
        if (count == 1) return NULL;
        if (count == n) return head->next;
        count -= n + 1;
        pointer = head;
        while(count > 0){
            pointer = pointer->next;
            count--;
        }
        pointer->next = pointer->next->next;
        return head;
    }
};

int main(){
    Solution S;
    vector<int> list = {1,2,3,4,5};
    int n = 2;
    ListNode* root = create(list);
    S.removeNthFromEnd(root, n);
    print_list_node(root);
    return 0;
}