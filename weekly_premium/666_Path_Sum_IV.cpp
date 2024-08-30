#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int ans = 0;
    struct Node{
        int dep;
        int pos;
        int val;
        Node* left;
        Node* right;
        Node(int d, int p, int v) : dep(d), pos(p), val(v), left(nullptr), right(nullptr) {}
        Node(int d, int p, int v, Node* l, Node* r) : dep(d), pos(p), val(v), left(l), right(r) {} 
    };
    void bfs(Node* root, int acc){
        acc += root->val;
        if (!root->left && !root->right) ans += acc;
        if (root->left) bfs(root->left, acc);
        if (root->right) bfs(root->right, acc);
        return;
    }
    int pathSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        Node* root = new Node(1, 1, nums[0] % 10);
        queue<Node*> que;
        que.push(root);
        for (int index = 1; index < nums.size(); index++){
            int dep = nums[index] / 100;
            int pos = (nums[index] / 10) % 10;
            int val = nums[index] % 10;
            Node* temp = new Node(dep, pos, val);
            while(!que.empty() && (que.front()->dep != dep - 1 || (pos + 1) / 2 != que.front()->pos)) que.pop();
            if (pos % 2 == 1) que.front()->left = temp;
            else que.front()->right = temp;
            que.push(temp);
        }
        bfs(root, 0);
        return ans;
    }
};

int main(){
    vector<int> nums = {113,215,221};
    // vector<int> nums = {113,221};
    // vector<int> nums = {111,217,221,315,415};
    Solution S;
    cout << S.pathSum(nums) << endl;
    return 0;
}