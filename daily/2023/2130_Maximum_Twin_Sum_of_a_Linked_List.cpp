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
    ListNode* pseudo = new ListNode();
    ListNode* temp = pseudo;
    for (auto i : nodes){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return pseudo->next;
}

void print_list(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        int M = 0;
        for (int i = 0; i < nums.size()/2; i++){
            M = max(M, nums[i] + nums[nums.size()-1-i]);
        }
        return M;
    }
};

int main(){
    // vector<int> nodes = {5,2,4,1};
    vector<int> nodes = {4,2,2,3};
    ListNode* head = create_list(nodes);
    Solution S;
    cout << S.pairSum(head) << endl;
    return 0;
}