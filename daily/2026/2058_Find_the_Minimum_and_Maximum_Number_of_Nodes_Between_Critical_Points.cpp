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
    ListNode* curr = head;
    for (int i = 1; i < nodes.size(); i++){
        curr->next = new ListNode(nodes[i]);
        curr = curr->next;
    }
    return head;
}

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> node;
        while(head){
            node.push_back(head->val);
            head = head->next;
        }
        int n = node.size();
        int first_critical = -1;
        int last_critical = -1;
        vector<int> ans = {100001, 0};
        for (int i = 1; i < n - 1; i++){
            if ((node[i] > node[i-1] && node[i] > node[i+1]) || (node[i] < node[i-1] && node[i] < node[i+1])){
                if (first_critical == -1) first_critical = i;
                if (last_critical != -1) ans[0] = min(ans[0], i - last_critical);
                last_critical = i;
            }
        }
        if (last_critical == -1 || last_critical == first_critical) return {-1, -1};
        ans[1] = last_critical - first_critical;
        return ans;
    }
};

int main(){
    vector<int> nodes = {3,1};
    // vector<int> nodes = {5,3,1,2,5,1,2};
    // vector<int> nodes = {1,3,2,2,3,2,2,2,7};
    ListNode* head = createList(nodes);
    Solution S;
    vector<int> ans = S.nodesBetweenCriticalPoints(head);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}