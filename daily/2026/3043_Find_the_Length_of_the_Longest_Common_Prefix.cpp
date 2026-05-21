#include <iostream>
#include <vector>

using namespace std;

struct Node{
    unordered_map<char, Node*> children;
    Node(){}
};

class Trie{
public:
    Trie(){
        root = new Node();
    }
    void insert(int x){
        string s = to_string(x);
        Node* ptr = root;
        for (char c : s){
            if (!ptr->children.count(c)) ptr->children[c] = new Node();
            ptr = ptr->children[c];
        }
    }
    int prefix(int x){
        Node* ptr = root;
        string s = to_string(x);
        int cnt = 0;
        for (char c : s){
            if (!ptr->children.count(c)) return cnt;
            ptr = ptr->children[c];
            cnt++;
        }
        return cnt;
    }

private:
    Node* root;
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie T;
        int ans = 0;
        for (int i : arr1) T.insert(i);
        for (int i : arr2) ans = max(ans, T.prefix(i));
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