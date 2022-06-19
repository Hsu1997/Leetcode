#include <iostream>
#include <vector>
#include <string>

using namespace std;

class trie{
    struct Node{
        vector<Node*> ch = vector<Node*>(26, NULL);
        bool is_word = false;
    };

    Node* root;

public:

    trie() {
        root = new Node();
    }

    void insert(string s){
        Node* now = root;

        for (char i : s){
            if (!now->ch[i-'a']) now->ch[i-'a'] = new Node();
            now = now->ch[i-'a'];
        }
        now->is_word = true;
    }

    void dfs(Node* now, vector<string> &ans, string &temp){
        if (ans.size() == 3) return;
        if (now->is_word) ans.push_back(temp);

        for (int i = 0; i < 26; i++){
            // cout << "start, i = " << i << endl;
            // cout << "temp = " << temp + (char)('a'+i) << endl;
            if (now->ch[i]){
                temp += (char)'a'+i;
                dfs(now->ch[i], ans, temp);
                temp.pop_back();
            }
            // cout << "end, i = " << i << endl;
        }
    }

    vector<vector<string>> search(string searchWord){
        Node* now = root;
        vector<vector<string>> ans;
        ans.resize(searchWord.length());
        string prefix;

        for (int i = 0; i < searchWord.length(); i++){
            prefix += searchWord[i];
            string temp = prefix;
            if (!now->ch[searchWord[i] - 'a']) return ans;
            now = now->ch[searchWord[i] - 'a'];
            // cout << "search : " << i << " th character, string = " << temp << " now = " << now << endl;
            dfs(now, ans[i], temp);
        }
        
        return ans;
    }    

};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        trie T;
        for (string str : products){
            // cout << str << " insert to : " << &T << endl;
            T.insert(str);
        }
        // for (auto i : T.ch['m'-'a']->ch['o'-'a']->ch['b'-'a']->ch['i'-'a']->ch['l'-'a']->ch){
        //     if (i == NULL) cout << "pass" << endl;
        //     else{
        //         if (i->is_word) cout << "end of the word!!" << endl;
        //         for (auto j : i->ch) cout << j << endl;
        //     }
        //     // cout << i << endl;
        // }
        vector<vector<string>> ans;
        ans = T.search(searchWord);
        return ans;
    }
};

int main(){
    // vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    // string searchWord = "mouse";
    // vector<string> products = {"havana"};
    // string searchWord = "havana";
    vector<string> products = {"bags","baggage","banner","box","cloths"};
    string searchWord = "bag";
    Solution S;

    vector<vector<string>> ans = S.suggestedProducts(products, searchWord);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}