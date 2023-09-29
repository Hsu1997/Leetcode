#include <iostream>
#include <vector>
#include <stdlib.h>

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

class Solution {
public:
    ListNode* h;

    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        ListNode* temp = h;
        double num = 1;
        int ans = INT_MIN;
        while(temp != nullptr){
            double x = (double)rand() / (double)(RAND_MAX + 1.0);
            // cout << x << " : ";
            if (x < (double)1 / num) ans = temp->val;
            num++;
            temp = temp->next;
            // cout << ans << endl;
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,2,3};
    ListNode* head = create_list(nodes);
    Solution* obj = new Solution(head);
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    return 0;
}