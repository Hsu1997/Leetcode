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
    int n = nodes.size();
    ListNode* head = new ListNode(nodes[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++){
        curr->next = new ListNode(nodes[i]);
        curr = curr->next;
    }
    return head;
}

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head){
            ans = ans * 2 + head->val;
            head = head->next;
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,0,1};
    // vector<int> nodes = {0};
    ListNode* head = create_list(nodes);
    Solution S;
    cout << S.getDecimalValue(head) << endl;
    return 0;
}