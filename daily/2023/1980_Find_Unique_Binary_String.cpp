#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node{
    node* zero;
    node* one;
    string s;
    node() : zero(nullptr), one(nullptr), s() {}
    node(string s) : zero(nullptr), one(nullptr), s(s) {}
};


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        node* root = new node();
        for (string s : nums){
            node* temp = root;
            for (char c : s){
                if (c == '0'){
                    if (!temp->zero) temp->zero = new node(temp->s + "0");
                    temp = temp->zero;
                }
                else{
                    if (!temp->one) temp->one = new node(temp->s + "1");
                    temp = temp->one;
                }
            }
        }
        queue<node*> que;
        string ans;
        que.push(root);
        while(!que.empty()){
            node* n = que.front();
            que.pop();
            if (n->zero) que.push(n->zero);
            else{
                ans = n->s + "0";
                break;
            }
            if (n->one) que.push(n->one);
            else{
                ans = n->s + "1";
                break;
            }
        }
        ans.append(string(nums.size()-ans.length(),'0'));
        return ans;
    }
};

int main(){
    vector<string> nums = {"01","10"};
    // vector<string> nums = {"00","01"};
    // vector<string> nums = {"111","011","001"};
    Solution S;
    cout << S.findDifferentBinaryString(nums) << endl;
    return 0;
}