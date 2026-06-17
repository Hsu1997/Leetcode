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

ListNode* createList(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    ListNode* head = new ListNode(nodes[0]);
    ListNode* ptr = head;
    int n = nodes.size();
    for (int i = 1; i < n; i++){
        ptr->next = new ListNode(nodes[i]);
        ptr = ptr->next;
    }
    return head;
}

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* ptr = head;
        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < n / 2; i++){
            ans = max(ans, v[i] + v[n - 1 - i]);
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {5,4,2,1};
    // vector<int> nodes = {4,2,2,3};
    // vector<int> nodes = {1,100000};
    ListNode* head = createList(nodes);
    Solution S;
    cout << S.pairSum(head) << endl;
    return 0;
}