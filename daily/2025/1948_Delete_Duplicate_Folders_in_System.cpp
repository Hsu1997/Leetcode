#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

struct Node{
    string serial;
    map<string, Node*> children;
};

class Trie{
public:
    Node* root;
    unordered_map<string, int> freq;

    Trie() : root(new Node()) {}

    void add_floder(vector<string>& path){
        Node* curr = root;
        for (string& p : path){
            if (curr->children.find(p) == curr->children.end()) curr->children[p] = new Node();
            curr = curr->children[p];
        }
    }

    void construct_subfloder(Node* curr){
        for (auto& [p, n] : curr->children){
            construct_subfloder(n);
            curr->serial += "(" + p + n->serial + ")";
        }
        if (curr->serial != "") freq[curr->serial]++;
    }

    vector<vector<string>> find_unique_floder(){
        vector<vector<string>> ans;
        for (auto& [child_path_name, child_node] : root->children){
            vector<string> curr_path = {child_path_name};
            dfs(child_node, curr_path, ans);
        }
        return ans;
    }

    void dfs(Node* node, vector<string>& curr_path, vector<vector<string>>& ans){
        if (node->serial != "" && freq[node->serial] > 1) return;
        ans.push_back(curr_path);
        for (auto& [child_path_name, child_node] : node->children){
            curr_path.push_back(child_path_name);
            dfs(child_node, curr_path, ans);
            curr_path.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie T;
        for (auto& path : paths) T.add_floder(path);
        T.construct_subfloder(T.root);
        return T.find_unique_floder();
    }
};

int main(){
    vector<vector<string>> paths = {{"a"},{"c"},{"d"},{"a","b"},{"c","b"},{"d","a"}};
    // vector<vector<string>> paths = {{"a"},{"c"},{"a","b"},{"c","b"},{"a","b","x"},{"a","b","x","y"},{"w"},{"w","y"}};
    // vector<vector<string>> paths = {{"a","b"},{"c","d"},{"c"},{"a"}};
    Solution S;
    vector<vector<string>> ans = S.deleteDuplicateFolder(paths);
    for (auto path : ans){
        for (auto s : path){
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}