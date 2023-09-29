#include <iostream>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* helper(vector<vector<int>>& grid, int start_row, int start_col, int size){
        // cout << "helper : size = " << size << ", start from " << start_row << ", " << start_col;
        Node* temp = new Node(grid[start_row][start_col], 1);
        // cout << ", this node val = " << temp->val << ", is_leaf = " << temp->isLeaf << endl;
        if (size == 1) return temp;
        for (int i = start_row; i < start_row + size; i++){
            for (int j = start_col; j < start_col + size; j++){
                if (grid[i][j] != temp->val) temp->isLeaf = 0;
                if (!temp->isLeaf) break;
            }
            if (!temp->isLeaf) break;
        }
        // cout << "this round size = " << size << endl;
        if (temp->isLeaf) return temp;
        temp->topLeft = helper(grid, start_row, start_col, size / 2);
        temp->topRight = helper(grid, start_row, start_col + size/2, size / 2);
        temp->bottomLeft = helper(grid, start_row + size/2, start_col, size / 2);
        temp->bottomRight = helper(grid, start_row + size/2, start_col + size/2, size / 2);
        return temp;
    }

    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }
};

int main(){
    vector<vector<int>> grid = {{0,1},{1,0}};
    Solution S;
    Node* ans = S.construct(grid);
    cout << ans->isLeaf << " " << ans->val << endl;
    cout << ans->topLeft->isLeaf << " " << ans->topLeft->val << endl;
    cout << ans->topRight->isLeaf << " " << ans->topRight->val << endl;
    cout << ans->bottomLeft->isLeaf << " " << ans->bottomLeft->val << endl;
    cout << ans->bottomRight->isLeaf << " " << ans->bottomRight->val << endl;

    return 0;
}