#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Node{
public:
    unordered_map<string, Node*> child;
    bool done;
    string s;
    Node(){
        done = false;
        s = "";
    }
};

class Trie{
public:
    Node* root;
    Trie(){
         root = new Node();
    }
    void Add_string(string route){
        if (route.empty() || route[0] != '/') return;
        int i = 1;
        int s = route.length();
        Node* curr = root;
        while(i < s){
            int next_ptr = i;
            while(next_ptr < s && route[next_ptr] != '/') next_ptr++;
            string floder = route.substr(i, next_ptr - i);
            if (curr->child.find(floder) == curr->child.end()){
                curr->child[floder] = new Node();
            }
            curr = curr->child[floder];
            i = next_ptr + 1;
        }
        curr->done = true;
        curr->s = route;
    }
};

class Solution {
public:
    vector<string> ans;
    void bfs(Node* node){
        if (node->done) ans.push_back(node->s);
        else{
            for (auto c : node->child){
                bfs(c.second);
            }
        } 
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* T = new Trie();
        for (string s : folder) T->Add_string(s);
        bfs(T->root);
        return ans;
    }
};

int main(){
    vector<string> floder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    // vector<string> floder = {"/a","/a/b/c","/a/b/d"};
    // vector<string> floder = {"/a/b/c","/a/b/ca","/a/b/d"};
    Solution S;
    vector<string> ans = S.removeSubfolders(floder);
    for (string s : ans) cout << s << " ";
    cout << endl;
}