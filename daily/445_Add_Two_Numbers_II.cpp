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

ListNode* create_link_list(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    ListNode* root = new ListNode(nodes[0]);
    ListNode* temp = root;
    for (int i = 1; i < nodes.size(); i++){
        temp->next = new ListNode(nodes[i]);
        temp = temp->next;
    }
    return root;
}

void print_link_list(ListNode* l){
    while(l){
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> n1;
        vector<int> n2;
        while(l1){
            n1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            n2.push_back(l2->val);
            l2 = l2->next;
        }
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        int len = max(n1.size(), n2.size());
        n1.resize(len+1);
        n2.resize(len+1);
        // for (auto i : n1) cout << i << " ";
        // cout << endl;
        // for (auto i : n2) cout << i << " ";
        // cout << endl;
        vector<int> ans(len+1);
        for (int i = 0; i < len; i++){
            ans[i] += n1[i] + n2[i];
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
        }
        // for (auto i : ans) cout << i << " ";
        // cout << endl;
        ListNode* root = new ListNode(ans[len]);
        ListNode* temp = root;
        for (int i = len-1; i >= 0; i--){
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        // print_link_list(root);
        if (root->val == 0) return root->next;
        return root;
    }
};

int main(){
    vector<int> v1 = {7,2,4,3};
    vector<int> v2 = {5,6,4};
    ListNode* l1 = create_link_list(v1);
    ListNode* l2 = create_link_list(v2);
    Solution S;
    ListNode* ans = S.addTwoNumbers(l1, l2);
    print_link_list(ans);
    return 0;
}