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
    return;
}

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* pseudo = new ListNode();
        ListNode* temp = pseudo;
        while(head){
            if (head->val == 0){
                if (head->next){
                    temp->next = new ListNode();
                    temp = temp->next;
                }
            }
            else{
                temp->val += head->val;
            }
            head = head->next;
        }
        temp = nullptr;
        return pseudo->next;;
    }
};

int main(){
    vector<int> nodes = {0,3,1,0,4,5,2,0};
    // vector<int> nodes = {0,1,0,3,0,2,2,0};
    ListNode* head = create_list(nodes);
    Solution S;
    ListNode* ans = S.mergeNodes(head);
    print_list(ans);
    return 0;
}