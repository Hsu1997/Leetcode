#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node{
    vector<node*> next;
    bool is_word = false;
    node() : next(26) {}
};

class trie {
public:
    node* root = new node();
    // trie() {}
    void insert(string s){
        node* temp = root;
        for (char c : s){
            if (!temp->next[c-'a']) temp->next[c-'a'] = new node();
            temp = temp->next[c-'a'];
        }
        temp->is_word = true;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie T;
        for (string s : dictionary) T.insert(s);
        string ans;
        string::iterator it = sentence.begin();
        while(it != sentence.end()){
            string temp = "";
            while(it != sentence.end() && *it != ' ') temp += *it++;
            node* temp_node = T.root;
            int i = 0;
            for (; i < temp.length(); i++){
                if (!temp_node->next[temp[i]-'a']){
                    i = temp.length();
                    break;
                }
                temp_node = temp_node->next[temp[i]-'a'];
                if (temp_node->is_word) break;
            }
            if (!ans.empty()) ans += " ";
            if (i == temp.length()) ans += temp;
            else ans += temp.substr(0, i+1);
            if (it != sentence.end()) it++;
        }
        return ans;
    }
};

int main(){
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    // vector<string> dictionary = {"a","b","c"};
    // string sentence = "aadsfasf absbs bbab cadsfafs";
    Solution S;
    cout << S.replaceWords(dictionary, sentence) << endl;
    return 0;
}