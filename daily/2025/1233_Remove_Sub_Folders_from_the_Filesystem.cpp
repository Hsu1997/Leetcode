#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Trie {
public:
    struct Node{
        bool is_done;
        unordered_map<string, Node*> children;
        Node(){is_done = false;}
    };

    Node* root;
    
    Trie(){
        root = new Node();
    }
    
    void add(string s){
        int n = s.length();
        Node* curr = root;
        int i = 1;
        while(i < n){
            int j = i;
            while(j < n && s[j] != '/') j++;
            string t = s.substr(i, j - i);
            if (curr->children.find(t) == curr->children.end()) curr->children[t] = new Node();
            curr = curr->children[t];
            i = j + 1;
        }
        curr->is_done = true;
    }

    vector<string> find_all_parent_folder(){
        vector<string> parent_floder;
        Node* curr = root;
        bfs(curr, "", parent_floder);
        return parent_floder;
    }

    void bfs(Node* curr, string path, vector<string>& parent_floder){
        if (curr->is_done){
            parent_floder.push_back(path);
            return;
        }
        for (auto& [f, next] : curr->children){
            bfs(next, path + '/' + f, parent_floder);
        }
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie *T = new Trie();
        for (string s : folder) T->add(s);
        return T->find_all_parent_folder();
    }
};

int main(){
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    // vector<string> folder = {"/a","/a/b/c","/a/b/d"};
    // vector<string> folder = {"/a/b/c","/a/b/ca","/a/b/d"};
    Solution S;
    vector<string> ans = S.removeSubfolders(folder);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}