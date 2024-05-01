// Time : O(n), Space : O(n)
// Reference : O(n) + O(1)

#include <iostream>
#include <map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        map<Node*, Node*> list;
        Node *pseudo = new Node(0);
        Node *current = pseudo;
        Node *root = head;
        while(head){
            current->next = new Node(head->val);
            list[head] = current->next;
            current = current->next;
            head = head->next;
        }
        current = pseudo->next;
        while(root){
            current->random = list[root->random];
            current = current->next;
            root = root->next;
        }
        return pseudo->next;
    }
};

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(!head)
//             return NULL;
//         Node* head_cp = NULL;
//         Node* curr = head;
//         Node* curr_cp = NULL;
// //(I)CONSTRUCTING THE NEW LIST WITH THE CURRENT VALUE AND THE NEXT VALUE WITH RANDOM SET AS NULL
//         while(curr!=NULL){
//             curr_cp = new Node(curr->val,curr->next,NULL);
//             curr->next = curr_cp;
//             curr = curr_cp->next;
//         }
// //(II)SETTING THE PREVIOUS NODE VALUE AT THIS STEP
//         curr = head;
//         while(curr!=NULL){
//             curr_cp = curr->next;
//             if(curr->random)
//                 curr_cp->random = curr->random->next;
//             curr = curr_cp->next;
//         }
// //(III) INORDER TO RETURN THE VALUES FROM THE NEW LIST WE NEED TO ARRANGE IT SUCH THAT PROPER ORDER WE CAN RETURN 
//         curr = head;
//         head_cp = head->next;
//         while(curr!=NULL){
//             curr_cp = curr->next;
//             curr->next = curr_cp->next; // making the question's list back to normal
//             curr = curr->next;
//             if(curr)
//                 curr_cp->next = curr->next;
//         }
//         return head_cp;
//     }
// };
