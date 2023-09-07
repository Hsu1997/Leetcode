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
    ListNode* pseudo = new ListNode();
    ListNode* temp = pseudo;
    for (auto i : nodes){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return pseudo->next;
}

void print_list(ListNode* root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* current = head;
        int s = 0;
        while(current){
            current = current->next;
            s++;
        }
        current = head;
        vector<ListNode*> ans;
        for(int i = 0; i < k; i++){
            ListNode* pseudo = new ListNode();
            ListNode* temp = pseudo;
            int partial = (s/k)+(s%k>0);
            if (s%k>0) s--;
            while(partial--){
                temp->next = current;
                temp = current;
                current = current->next;
            }
            temp->next = nullptr;
            ans.push_back(pseudo->next);
        }
        return ans;
    }
};

int main(){
    // vector<int> nodes = {1,2,3};
    // int k = 5;
    vector<int> nodes = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;
    ListNode* head = create_list(nodes);
    Solution S;
    vector<ListNode*> ans = S.splitListToParts(head, k);
    for (auto i : ans) print_list(i);
    return 0;
}