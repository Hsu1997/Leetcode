#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    int position;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right){}
};

TreeNode* CreateTree(vector<int> nums){
    if (nums.size() == 0) return nullptr;
    // if (nums.size() == 1) return new TreeNode(nums[0]);
    TreeNode* root = new TreeNode(nums[0]);
    root->position = 0;
    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        int temp_position = temp->position;
        if (temp_position*2+1 < nums.size() && nums[temp_position*2+1] != -1){
            temp->left = new TreeNode(nums[temp_position*2+1]);
            temp->left->position = temp_position*2+1;
            que.push(temp->left);
        }
        if (temp_position*2+2 < nums.size() && nums[temp_position*2+2] != -1){
            temp->right = new TreeNode(nums[temp_position*2+2]);
            temp->right->position = temp_position*2+2;
            que.push(temp->right);
        }
    }
    return root;
}

void PrintTree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        cout << temp->val << " ";
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
    cout << endl;
}

class BSTIterator {
public:
    stack<TreeNode*> temp;
    
    BSTIterator(TreeNode* root) {
        while(root != nullptr){
            temp.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* now = temp.top();
        temp.pop();
        int ans = now->val;
        now = now->right;
        while(now != nullptr){
            temp.push(now);
            now = now->left;
        }
        // cout << ans << " ";
        return ans;
    }
    
    bool hasNext() {
        // if (!temp.empty()) cout << "True ";
        // else cout << "False ";
        return !temp.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
**/

int main(){
    vector<int> nums = {7, 3, 15, -1, -1, 9, 20};
    TreeNode* root = CreateTree(nums);

    BSTIterator* bSTIterator = new BSTIterator(root);
    bSTIterator->next();    // return 3
    bSTIterator->next();    // return 7
    bSTIterator->hasNext(); // return True
    bSTIterator->next();    // return 9
    bSTIterator->hasNext(); // return True
    bSTIterator->next();    // return 15
    bSTIterator->hasNext(); // return True
    bSTIterator->next();    // return 20
    bSTIterator->hasNext(); // return False
    cout << endl;
    return 0;
}
