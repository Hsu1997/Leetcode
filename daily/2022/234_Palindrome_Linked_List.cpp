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

ListNode* create_link_list(vector<int> node){
    if (node.empty()) return nullptr;

    ListNode* pseudo = new ListNode();
    ListNode* now = pseudo;
    for (auto i : node){
        now->next = new ListNode(i);
        now = now->next;
    }
    return pseudo->next;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return false;

        vector<int> node;
        while(head != nullptr){
            node.push_back(head->val);
            head = head->next;
        }
        int i = 0;
        int j = node.size()-1;
        while(i <= j){
            if (node[i] != node[j]) return false;
            i++, j--;
        }
        return true;
    }
};

int main(){
    vector<int> node = {1,2,3,2,1};
    ListNode* head = create_link_list(node);
    Solution S;
    cout << S.isPalindrome(head) << endl;
    return 0;
}