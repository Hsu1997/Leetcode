#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ans = NULL;
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while(tempA != NULL){
            tempA->val *= -1;
            tempA = tempA->next;
        }
        while(tempB != NULL && tempB->val > 0){
            tempB = tempB->next;
        }
        if (tempB) ans = tempB;

        tempA = headA;
        tempA->val *= -1;
        while(tempA->next != NULL){
            tempA = tempA->next;
            tempA->val *= -1;
        }

        return ans;
    }
};

int main(){
    vector<int> listA = {2,6,4};
    vector<int> listB = {1,5};
    int intersectionA = 3;
    int intersectionB = 2;
    ListNode *sudoA = new ListNode(0);
    ListNode *sudoB = new ListNode(0);
    ListNode *tempA = sudoA;
    ListNode *tempB = sudoB;

    for (auto i : listA){
        tempA->next = new ListNode(i);
        tempA = tempA->next;
    }
    for (int i = 0; i < intersectionB; i++){
        tempB->next = new ListNode(listB[i]);
        tempB = tempB->next;
    }
    tempA = sudoA->next;
    for (int i = 0; i < intersectionA; i++) tempA = tempA->next;
    if (tempA) tempB->next = tempA;

    ListNode *headA = sudoA->next;
    ListNode *headB = sudoB->next;

    // while(headA != NULL){
    //     cout << headA->val << " ";
    //     headA = headA->next;
    // }
    // cout << endl;
    // while(headB != NULL){
    //     cout << headB->val << " ";
    //     headB = headB->next;
    // }
    // cout << endl;
    // headA = sudoA->next;
    // headB = sudoB->next;

    Solution S;
    ListNode* ans = S.getIntersectionNode(headA, headB);
    if (ans) cout << ans->val << endl;
    else cout << 0 << endl;

    return 0;
}