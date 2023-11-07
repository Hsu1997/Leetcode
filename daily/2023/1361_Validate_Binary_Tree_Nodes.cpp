#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<bool> is_root;
    vector<bool> visited;

    bool dfs(int i, vector<int>& leftChild, vector<int>& rightChild){
        if (i == -1) return true;
        if (visited[i]) return false;
        visited[i] = true;
        if (!dfs(leftChild[i], leftChild, rightChild)) return false;
        if (!dfs(rightChild[i], leftChild, rightChild)) return false;
        return true;
    };

    bool validateBinaryTreeNodes(int _n, vector<int>& leftChild, vector<int>& rightChild) {
        n = _n;
        is_root = vector<bool>(n, true);
        visited = vector<bool>(n, false);
        for (int i = 0; i < n; i++){
            if (leftChild[i] != -1) is_root[leftChild[i]] = false;
            if (rightChild[i] != -1) is_root[rightChild[i]] = false;
        }
        int root = -1;
        for (int i = 0; i < n; i++){
            if (is_root[i]){
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;
        if (dfs(root, leftChild, rightChild) == false) return false;
        for (auto i : visited) if (!i) return false;
        return true;
    }
};

int main(){
    // int n = 4;
    // vector<int> leftChild = {1,-1,3,-1};
    // vector<int> rightChild = {2,-1,-1,-1};
    // int n = 4;
    // vector<int> leftChild = {1,-1,3,-1};
    // vector<int> rightChild = {2,3,-1,-1};
    // int n = 2;
    // vector<int> leftChild = {1,0};
    // vector<int> rightChild = {-1,-1};
    int n = 6;
    vector<int> leftChild = {1,-1,-1,4,-1,-1};
    vector<int> rightChild = {2,-1,-1,5,-1,-1};
    Solution S;
    cout << S.validateBinaryTreeNodes(n, leftChild, rightChild) << endl;
    return 0;
}