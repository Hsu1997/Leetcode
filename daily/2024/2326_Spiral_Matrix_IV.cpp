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

ListNode* create_list(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    ListNode* head = new ListNode(nodes[0]);
    ListNode* temp = head;
    for (int i = 1; i < nodes.size(); i++){
        temp->next = new ListNode(nodes[i]);
        temp = temp->next;
    }
    return head;
}

class Solution {
public:
    bool in_field(int x, int y, int m, int n){
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> table(m, vector<int>(n, -1));
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0;
        int x = 0, y = 0;
        while(head){
            table[x][y] = head->val;
            if (!in_field(x + dir[d][0], y + dir[d][1], m, n) || table[x + dir[d][0]][y + dir[d][1]] != -1) d = (d + 1) % 4;
            x += dir[d][0];
            y += dir[d][1];
            head = head->next;
        }
        return table;
    }
};

int main(){
    int m = 3;
    int n = 5;
    vector<int> nodes = {3,0,2,6,8,1,7,9,4,2,5,5,0};
    // int m = 1;
    // int n = 4;
    // vector<int> nodes = {0,1,2};
    ListNode* head = create_list(nodes);
    Solution S;
    vector<vector<int>> ans = S.spiralMatrix(m, n, head);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}