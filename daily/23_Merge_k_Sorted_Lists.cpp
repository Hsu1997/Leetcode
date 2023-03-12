#include <iostream>
#include <vector>
#include <queue>

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
    for (auto i : nodes) temp->next = new ListNode(i), temp = temp->next;
    return pseudo->next;
}

void print_list(ListNode* list){
    ListNode* temp = list;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    return;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* pseudo = new ListNode();
        ListNode* it = pseudo;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for (auto i : lists) if (i) pq.push(make_pair(i->val, i));
        while(!pq.empty()){
            pair<int, ListNode*> temp = pq.top();
            pq.pop();
            it->next = temp.second;
            it = it->next;
            if (temp.second->next) pq.push(make_pair(temp.second->next->val, temp.second->next));
        }
        return pseudo->next;
    }
};

int main(){
    // vector<vector<int>> list = {{1,4,5},{1,3,4},{2,6}};
    // vector<vector<int>> list = {};
    vector<vector<int>> list = {{}};
    vector<ListNode*> lists;
    for (auto i : list) lists.push_back(create_list(i));
    Solution S;
    ListNode* ans = S.mergeKLists(lists);
    print_list(ans);
    return 0;
}