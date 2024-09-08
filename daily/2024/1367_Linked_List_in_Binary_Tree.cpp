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

TreeNode* create_tree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    int i = 1;
    que.push(root);
    while(i < n && !que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < n && nodes[i] != -1){
            temp->left = new TreeNode(nodes[i]);
            que.push(temp->left);
        }
        i++;
        if (i < n && nodes[i] != -1){
            temp->right = new TreeNode(nodes[i]);
            que.push(temp->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;
        if (root == nullptr) return false;
        if (head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right))) return true;
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;
        if (dfs(head, root)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

// class Solution {
// public:
//     ListNode* head;
//     bool dfs(ListNode* curr_list, TreeNode* root){
//         if (curr_list == nullptr) return true;
//         if (root == nullptr) return false;
//         if (curr_list->val == root->val && dfs(curr_list->next, root->left)) return true;
//         if (curr_list->val == root->val && dfs(curr_list->next, root->right)) return true;
//         if (curr_list == head && dfs(head, root->left)) return true;
//         if (curr_list == head && dfs(head, root->right)) return true;
//         return false;
//     }
//     bool isSubPath(ListNode* head, TreeNode* root) {
//         this->head = head;
//         return dfs(head, root);
//     }
// };

int main(){
    vector<int> list = {4,2,8};
    vector<int> tree = {1,4,4,-1,2,2,-1,1,-1,6,8,-1,-1,-1,-1,1,3};
    // vector<int> list = {1,4,2,6};
    // vector<int> tree = {1,4,4,-1,2,2,-1,1,-1,6,8,-1,-1,-1,-1,1,3};
    // vector<int> list = {1,4,2,6,8};
    // vector<int> tree = {1,4,4,-1,2,2,-1,1,-1,6,8,-1,-1,-1,-1,1,3};
    ListNode* head = create_list(list);
    TreeNode* root = create_tree(tree);
    Solution S;
    cout << S.isSubPath(head, root) << endl;
    return 0;
}