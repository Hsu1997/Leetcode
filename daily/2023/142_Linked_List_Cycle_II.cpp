#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(vector<int> nodes, int repeat){
    if (nodes.empty()) return nullptr;
    ListNode* pseudo = new ListNode(0);
    ListNode* temp = pseudo;
    int cnt = 0;
    ListNode* rep;
    for (auto i : nodes){
        temp->next = new ListNode(i);
        temp = temp->next;
        cnt++;
        if (cnt == repeat) rep = temp;
    }
    temp->next = rep;
    return pseudo->next;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // x : where the cycle begins
        // r : the distance of fast pointer and slow pointer meet after the cycle begins
        // c : the distance of the cycle
        // 2(x+r) = x+r+nc
        // x+r = nc
        // x = nc-r
        // one pointer at head, one pointer at two pointer first meet(x+r)
        // x = x + nc = (x+r) + (nc - r)
        // when they meet, there is the solution
        ListNode* fast = head;
        ListNode* slow = head;
        if (fast->next == nullptr || fast->next->next == nullptr || slow->next == nullptr) return nullptr;
        fast = fast->next->next;
        slow = slow->next;
        while(fast->next != nullptr && fast->next->next != nullptr && slow->next != nullptr && fast != slow){
            // cout << "fast = " << fast->val << ", slow = " << slow->val << endl;
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next == nullptr || fast->next->next == nullptr || slow->next == nullptr) return nullptr;
        // cout << "meet at point " << fast->val << endl;
        while(head != fast){
            head = head->next;
            fast = fast->next;
        }
        return head;
    }
};

int main(){
    // vector<int> nodes = {3,2,0,-4};
    // ListNode* head = create_list(nodes,2);
    // vector<int> nodes = {1,2};
    // ListNode* head = create_list(nodes,1);
    vector<int> nodes = {1};
    ListNode* head = create_list(nodes,0);
    Solution S;
    ListNode* ans = S.detectCycle(head);
    if (ans) cout << ans->val << endl;
    else cout << -1 << endl;
    return 0;
}