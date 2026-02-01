#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Node{
    Node* child[26] = {nullptr};
    int idx = -1;
    Node(){}
};

class Trie{
public:
    Node* root;

    Trie() : root(new Node()) {}

    void add(const string& s, int i){
        Node* r = root;
        for (char c : s){
            int v = c - 'a';
            if (r->child[v] == nullptr) r->child[v] = new Node();
            r = r->child[v];
        }
        r->idx = i;
    }
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const long long inf = (1LL << 60);
        int idx = 0;
        unordered_map<string, int> stringToIdx;
        Trie T;
        for (string& s : original){
            if (stringToIdx.count(s)) continue;
            stringToIdx[s] = idx;
            T.add(s, idx);
            idx++;
        }
        for (string& s : changed){
            if (stringToIdx.count(s)) continue;
            stringToIdx[s] = idx;
            T.add(s, idx);
            idx++;
        }
        vector<vector<long long>> d(idx, vector<long long>(idx, inf));
        for (int i = 0; i < original.size(); i++){
            int u = stringToIdx[original[i]];
            int v = stringToIdx[changed[i]];
            d[u][v] = min(d[u][v], 1LL * cost[i]);
        }
        for (int i = 0; i < idx; i++) d[i][i] = 0;
        for (int k = 0; k < idx; k++){
            for (int i = 0; i < idx; i++){
                if (d[i][k] >= inf) continue;
                for (int j = 0; j < idx; j++){
                    if (d[k][j] >= inf) continue;
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int n = source.length();
        // dp[i] = total cost by changed [0 : i - 1]
        vector<long long> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            if (dp[i-1] >= inf) continue;
            Node* currSource = T.root;
            Node* currTarget = T.root;
            if (source[i-1] == target[i-1]) dp[i] = min(dp[i], dp[i-1]);
            for (int j = i - 1; j < n; j++){
                currSource = currSource->child[source[j] - 'a'];
                currTarget = currTarget->child[target[j] - 'a'];
                if (currSource == nullptr || currTarget == nullptr) break;
                if (currSource->idx != -1 && currTarget->idx != -1){
                    long long w = d[currSource->idx][currTarget->idx];
                    if (w < inf) dp[j+1] = min(dp[j+1], dp[i-1] + w);
                }
            }
        }
        return dp[n] >= inf? -1 : dp[n];
    }
};

int main(){
    string source = "abcd";
    string target = "acbe";
    vector<string> original = {"a","b","c","c","e","d"};
    vector<string> changed = {"b","c","b","e","b","e"};
    vector<int> cost = {2,5,5,1,2,20};
    // string source = "abcdefgh";
    // string target = "acdeeghh";
    // vector<string> original = {"bcd","fgh","thh"};
    // vector<string> changed = {"cde","thh","ghh"};
    // vector<int> cost = {1,3,5};
    // string source = "abcdefgh";
    // string target = "addddddd";
    // vector<string> original = {"bcd","defgh"};
    // vector<string> changed = {"ddd","ddddd"};
    // vector<int> cost = {100,1578};
    // string source = "fjybg";
    // string target = "apyyt";
    // vector<string> original = {"bg","xr","cc","ip","vq","po","ym","rh","vw","lf","lo","ee","qv","yr","f","w","i","u","g","a","e","f","s","r","p","j","o","g","i","u"};
    // vector<string> changed = {"xr","cc","ip","vq","po","ym","rh","vw","lf","lo","ee","qv","yr","yt","w","i","u","g","a","e","f","s","r","p","a","o","g","i","u","p"};
    // vector<int> cost = {97733,90086,87125,85361,75644,46301,21616,79538,52507,95884,79353,61127,58665,96031,95035,12116,41158,91096,47819,88522,25493,80186,66981,87597,56691,86820,89031,99954,41271,39699};
    Solution S;
    cout << S.minimumCost(source, target, original, changed, cost) << endl;
    return 0;
}