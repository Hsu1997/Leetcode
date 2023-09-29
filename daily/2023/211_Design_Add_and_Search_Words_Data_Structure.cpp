#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class WordDictionary {
public:
    struct node{
        map<char, node*> next;
        bool is_word = false;
    };

    node* root;

    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* temp = root;
        for (auto i : word){
            if (!temp->next.count(i)) temp->next[i] = new node();
            temp = temp->next[i];
        }
        temp->is_word = true;
    }
    
    bool search(string word) {
        // cout << "search word : " << word << endl;
        return search_helper(word, root);
    }

    bool search_helper(string s, node* n){
        int l = s.length();
        for (int i = 0; i < l; i++){
            char c = s[i];
            if (c == '.'){
                // if (i == s.length()-1 && n->next.empty()) return false;
                for (auto it = n->next.begin(); it != n->next.end(); it++){
                    // cout << "search substring : " << s.substr(i+1) << endl;
                    if (search_helper(s.substr(i+1), it->second)) return true;
                }
                return false;
            }
            else{
                // cout << "not . searching " << s << endl;
                if(!n->next.count(c)) return false;
                n = n->next[c];
            }
        }
        return n->is_word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
    // WordDictionary* wordDictionary = new WordDictionary();
    // wordDictionary->addWord("bad");
    // wordDictionary->addWord("dad");
    // wordDictionary->addWord("mad");
    // cout << wordDictionary->search("pad") << endl; // return False
    // cout << wordDictionary->search("bad") << endl; // return True
    // cout << wordDictionary->search(".ad") << endl; // return True
    // cout << wordDictionary->search("b..") << endl; // return True

    WordDictionary* wordDictionary = new WordDictionary();
    wordDictionary->addWord("a");
    wordDictionary->addWord("a");
    cout << wordDictionary->search(".") << endl; // return True
    cout << wordDictionary->search("a") << endl; // return True
    cout << wordDictionary->search("aa") << endl; // return False
    cout << wordDictionary->search("a") << endl; // return True
    cout << wordDictionary->search(".a") << endl; // return False
    cout << wordDictionary->search("a.") << endl; // return False

    return 0;
}