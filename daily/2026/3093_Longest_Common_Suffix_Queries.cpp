#include <iostream>
#include <vector>

using namespace std;

int max_len = 5001;

struct Node{
    int index;
    int l;
    array<int, 26> children{};
    Node() : index(max_len), l(max_len){children.fill(-1);}
    Node(int x) : index(x), l(0){children.fill(-1);}
};

class Trie{
public:
    // Node* root;
    vector<Node> nodes;
    Trie(int x){
        nodes.push_back(Node(x));
    }
    void insert(string& s, int idx){
        int curr = 0;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--){
            int c = s[i] - 'a';
            if (nodes[curr].children[c] == -1){
                nodes[curr].children[c] = nodes.size();
                nodes.push_back(Node());
            }
            curr = nodes[curr].children[c];
            if (n < nodes[curr].l){
                nodes[curr].index = idx;
                nodes[curr].l = n;
            }
        }
    }
    int find(string& s){
        int n = s.length();
        int curr = 0;
        for (int i = n - 1; i >= 0; i--){
            int c = s[i] - 'a';
            if (nodes[curr].children[c] != -1){
                curr = nodes[curr].children[c];
            }
            else break;
        }
        return nodes[curr].index;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();
        vector<int> ans(n);
        int l = INT_MAX;
        int idx = -1;
        for (int i = 0; i < m; i++){
            if (wordsContainer[i].length() < l){
                l = wordsContainer[i].length();
                idx = i;
            }
        }
        Trie T(idx);
        for (int i = 0; i < m; i++) T.insert(wordsContainer[i], i);
        for (int i = 0; i < n; i++) ans[i] = T.find(wordsQuery[i]);
        return ans;
    }
};

int main(){
    vector<string> wordsContainer = {"abcd","bcd","xbcd"};
    vector<string> wordsQuery = {"cd","bcd","xyz"};
    // vector<string> wordsContainer = {"abcdefgh","poiuygh","ghghgh"};
    // vector<string> wordsQuery = {"gh","acbfgh","acbfegh"};
    Solution S;
    vector<int> ans = S.stringIndices(wordsContainer, wordsQuery);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}