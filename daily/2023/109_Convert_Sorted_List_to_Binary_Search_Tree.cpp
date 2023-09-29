#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

void print_tree(TreeNode* root){
    if (root == nullptr) return;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (temp) cout << temp->val << " ";
        else cout << "null ";
        if (temp->left || temp->right){
            if (temp->left) que.push(temp->left);
            // else que.push(nullptr);
            if (temp->right) que.push(temp->right);
            // else que.push(nullptr);
        }
    }
    return;
}

class Solution {
public:
    int n;
    vector<int> nodes;

    TreeNode* subprocess(int start, int end){
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        if (start == end) return root;
        root->left = subprocess(start, mid-1);
        root->right = subprocess(mid+1, end);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        while(head){
            nodes.push_back(head->val);
            head = head->next;
        }
        n = nodes.size();
        return subprocess(0, n-1);
    }
};

int main(){
    vector<int> nodes = {-10,-3,0,5,9};
    ListNode* head = create_list(nodes);
    Solution S;
    TreeNode* ans = S.sortedListToBST(head);
    print_tree(ans);
    return 0;
}