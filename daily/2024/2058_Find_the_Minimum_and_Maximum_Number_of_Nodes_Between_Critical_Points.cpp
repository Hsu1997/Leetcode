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

ListNode* create_list(vector<int> nums){
    ListNode* pseudo = new ListNode();
    ListNode* temp = pseudo;
    for (int i : nums){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return pseudo->next;
}

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr) return {-1,-1};
        int count = 1;
        int pre_node_val = head->val;
        int pre_critical_node = -1;
        int first_critical_node = -1;
        head = head->next;
        vector<int> ans = {INT_MAX,INT_MIN};

        while(head->next){
            if ((head->val > pre_node_val && head->val > head->next->val) || (head->val < pre_node_val && head->val < head->next->val)){
                // critical_node.push_back(count);
                if (pre_critical_node == -1) first_critical_node = count, pre_critical_node = count;
                else{
                    ans[0] = min(ans[0], count - pre_critical_node);
                    pre_critical_node = count;
                }
            }
            pre_node_val = head->val;
            head = head->next;
            count++;
        }
        if (pre_critical_node == first_critical_node) return {-1,-1};
        ans[1] = pre_critical_node - first_critical_node;
        return ans;
    }
};

int main(){
    vector<int> nodes = {3,1};
    // vector<int> nodes = {5,3,1,2,5,1,2};
    // vector<int> nodes = {1,3,2,2,3,2,2,2,7};
    ListNode* head = create_list(nodes);
    Solution S;
    vector<int> ans = S.nodesBetweenCriticalPoints(head);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}