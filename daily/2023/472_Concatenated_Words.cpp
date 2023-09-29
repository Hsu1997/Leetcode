#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct trie{
    bool is_word = false;
    string meaning;
    unordered_map<int, trie*> child;
};

void insert(trie* root, string word){
    trie* temp = root;
    string temp_word = "";
    for (auto i : word){
        if (!temp->child.count(i)) temp->child[i] = new trie();
        temp = temp->child[i];
        temp_word += i;
        temp->meaning = temp_word;
    }
    temp->is_word = true;
}

class Solution {
public:
    vector<string> ans;
    trie* root;

    bool dfs(string s, trie* node, int start, int done){
        if (start == s.length()){
            // cout << "Is this answer? " << endl;
            if(node->is_word && done > 0){
                ans.push_back(s);
                // cout << "Find the answer" << endl;
                return true;
            }
            else{
                // cout << "No" << endl;
                return false;
            }
        }

        // cout << "dfs : " << s[start] << ", done = " << done;
        if (node->is_word == true){
            // cout << " => new one" << endl;
            if (dfs(s, root, start, done+1)) return true;
        }

        if (node->child.count(s[start]) == 0) return false;
        else{
            // cout << " => continue" << endl;
            if (dfs(s, node->child[s[start]], start+1, done)) return true;
        }
        return false;
    }

    void is_concatenated(string word){
        // cout << "now checking " << word << " : " << endl;
        dfs(word, root, 0, 0);
        // cout << endl;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new trie();
        for (string word : words) insert(root, word);

        // cout << "root " << root->is_word << endl;
        // while(!root->is_word){
        //     root = root->child.begin()->second;
        //     cout << root->meaning << endl;
        // }
        
        for (string word : words){
            is_concatenated(word);
        }

        return ans;
    }
};

int main(){
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    // vector<string> words = {"cat","dog","catdog"};
    Solution S;
    vector<string> ans = S.findAllConcatenatedWordsInADict(words);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}