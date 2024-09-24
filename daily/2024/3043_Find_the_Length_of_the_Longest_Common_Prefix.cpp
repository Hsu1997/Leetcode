#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Node{
    unordered_map<char, Node*> child;
    Node() {}
};

class Trie{
public:
    Node* root;
    Trie() : root(new Node()) {}
    void add_word(int i){
        string s = to_string(i);
        Node* curr = root;
        for (char c : s){
            if (curr->child.find(c) == curr->child.end()) curr->child[c] = new Node();
            curr = curr->child[c];
        }
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie T;
        int ans = 0;
        for (int i : arr1) T.add_word(i);
        for (int i : arr2){
            string s = to_string(i);
            Node* curr = T.root;
            int temp_len = 0;
            for (char c : s){
                if (curr->child.find(c) == curr->child.end()) break;
                temp_len++;
                ans = max(ans, temp_len);
                curr = curr->child[c];
            }
        }
        return ans;
    }
};

int main(){
    vector<int> arr1 = {1,10,100};
    vector<int> arr2 = {1000};
    // vector<int> arr1 = {1,2,3};
    // vector<int> arr2 = {4,4,4};
    Solution S;
    cout << S.longestCommonPrefix(arr1, arr2) << endl;
    return 0;
}