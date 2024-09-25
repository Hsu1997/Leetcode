#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Node{
    unordered_map<char, Node*> child;
    int score;
    Node() : score(0) {}
};

class Trie{
public:
    Node* root;
    Trie() : root(new Node()) {}

    void add_word(string& s){
        Node* temp = root;
        for (char c : s){
            if (temp->child.find(c) == temp->child.end()) temp->child[c] = new Node();
            temp = temp->child[c];
            temp->score++;
        }
    }

    int find_score(string& s){
        int score = 0;
        Node* curr = root;
        for (char c : s){
            curr = curr->child[c];
            score += curr->score;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* T = new Trie();
        for (string s : words){
            T->add_word(s);
        }
        int n = words.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            ans[i] = T->find_score(words[i]);
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"abc","ab","bc","b"};
    // vector<string> words = {"abcd"};
    Solution S;
    vector<int> ans = S.sumPrefixScores(words);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}