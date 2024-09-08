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

ListNode* create_linked_list(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    ListNode* root = new ListNode(nodes[0]);
    ListNode* temp = root;
    for (int i = 1; i < nodes.size(); i++){
        temp->next = new ListNode(nodes[i]);
        temp = temp->next;
    }
    return root;
}

void print_linked_list(ListNode* root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        while(temp) count++, temp = temp->next;
        temp = head;
        vector<ListNode*> ans(k, nullptr);
        for (int i = 0; i < k; i++){
            if (count / k == 0 && i >= count % k) continue;
            ans[i] = temp;
            int curr_count = 1;
            int curr_len = count / k + (i < count % k);
            while(curr_count < curr_len){
                temp = temp->next, curr_count++;
            }
            ListNode* ptr = temp;
            temp = temp->next;
            ptr->next = nullptr;
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,2,3};
    int k = 5;
    // vector<int> nodes = {1,2,3,4,5,6,7,8,9,10};
    // int k = 3;
    ListNode* head = create_linked_list(nodes);
    Solution S;
    vector<ListNode*> ans = S.splitListToParts(head, k);
    for (ListNode* i : ans) print_linked_list(i);
    return 0;
}