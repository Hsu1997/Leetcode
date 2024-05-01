// using Sentinel (Pseudo Head) to prevent the edge problem is the better way

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

ListNode* CreateNode(vector<int> nums){
    ListNode* pseudo = new ListNode();
    ListNode* current = pseudo;
    for (int i : nums){
        current->next = new ListNode(i);
        current = current->next;
    }
    return pseudo->next;
}

void PrintList(ListNode* root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

class Solution {
public:
    // ListNode* deleteDuplicates(ListNode* head) {
    //     if (head == nullptr) return head;
    //     // find the head
    //     bool flag = false;
    //     while(!flag){
    //     int now = head->val;
    //     if (head->next != nullptr && head->next->val == now) {
    //         while (head->val == now){
    //             if (head->next == nullptr) return nullptr;
    //             head = head->next;
    //         }
    //     } 
    //     else if (head == nullptr || head->next == nullptr) return head;
    //     else flag = true;
    //     }
    //     // before tail is done
    //     ListNode* tail = head;
    //     // // deal with body
    //     ListNode* front = tail->next;
    //     while(front != nullptr){
    //         ListNode* current = front;
    //         int now = front->val;
    //         while (current->next != nullptr && current->next->val == now) current = current->next;
    //         if (front == current){
    //             tail = current;
    //         }
    //         else tail->next = current->next;
    //         front = tail->next;
    //     }
    //     return head;
    // }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pseudo = new ListNode(0, head);
        ListNode* done = pseudo;
        while(head != nullptr){
            if (head->next != nullptr && head->next->val == head->val){
                while(head->next != nullptr && head->next->val == head->val) head = head->next;
                done->next = head->next;
            }
            else done = done->next;
            head = done->next;
        }
        return pseudo->next;
    }
};

int main(){
    // vector<int> nums = {1,1,2,3,4,4,5,5,6,7,7,8,9};
    vector<int> nums = {1,1};
    ListNode* root = CreateNode(nums);
    // PrintList(root);
    Solution S;
    PrintList(S.deleteDuplicates(root));
    return 0;
}