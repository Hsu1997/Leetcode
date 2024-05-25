#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tier {
public:
    struct node{
        bool is_word = false;
        vector<node*> next;
        node() : is_word(false), next(26,nullptr) {}
    };

    node* root;
    
    Tier(){
        root = new node();
    }

    void add_word(string s){
        node* temp = root;
        for (char c : s){
            if (temp->next[c-'a'] == nullptr) temp->next[c-'a'] = new node();
            temp = temp->next[c-'a'];
        }
        temp->is_word = true;
        return;
    }
    
};

class Solution {
public:
    vector<string> ans;
    vector<string> temp_ans;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Tier* t = new Tier();
        for (string s : wordDict) t->add_word(s);
        dfs(s, t, 0);
        return ans;
    }

    void dfs(string& s, Tier* t, int index){
        if (index == s.length()){
            string combine_ans;
            for (auto i : temp_ans) combine_ans += i + " ";
            combine_ans.pop_back();
            ans.push_back(combine_ans);
            return;
        }

        Tier::node* temp = t->root;
        for (int i = index; i < s.length(); i++){
            if (temp->next[s[i]-'a'] == nullptr) return;
            temp = temp->next[s[i]-'a'];
            if (temp->is_word){
                temp_ans.push_back(s.substr(index, i - index + 1));
                dfs(s, t, i+1);
                temp_ans.pop_back();
            }
        }
        return;
    }
};

int main(){
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    // string s = "pineapplepenapple";
    // vector<string> wordDict = {"apple","pen","applepen","pine","pineapple"};
    // string s = "catsandog";
    // vector<string> wordDict = {"cats","dog","sand","and","cat"};
    Solution S;
    vector<string> ans = S.wordBreak(s, wordDict);
    for (auto i : ans) cout << i << endl;
    return 0;
}