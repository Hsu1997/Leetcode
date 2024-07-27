#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = target.size();
        int INF = 1e9+7;
        vector<vector<int>> shortest_path(26, vector<int>(26, INF));
        
        for (int i = 0; i < 26; i++) shortest_path[i][i] = 0;
        for (int i = 0; i < cost.size(); i++) shortest_path[original[i]-'a'][changed[i]-'a'] = min(shortest_path[original[i]-'a'][changed[i]-'a'], cost[i]);
        
        for (int k = 0; k < 26; k++){
            for (int i = 0; i < 26; i++){
                for (int j = 0; j < 26; j++){
                    shortest_path[i][j] = min(shortest_path[i][j], shortest_path[i][k] + shortest_path[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++){
            if (shortest_path[source[i]-'a'][target[i]-'a'] == INF) return -1;
            ans += shortest_path[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};

int main(){
    string source = "abcd";
    string target = "acbe";
    vector<char> original = {'a','b','c','c','e','d'};
    vector<char> changed = {'b','c','b','e','b','e'};
    vector<int> cost = {2,5,5,1,2,20};
    // string source = "aaaa";
    // string target = "bbbb";
    // vector<char> original = {'a','c'};
    // vector<char> changed = {'c','b'};
    // vector<int> cost = {1,2};
    // string source = "abcd";
    // string target = "abce";
    // vector<char> original = {'a'};
    // vector<char> changed = {'e'};
    // vector<int> cost = {10000};
    // string source = "aaadbdcdac";
    // string target = "cdbabaddba";
    // vector<char> original = {'a','c','b','d','b','a','c'};
    // vector<char> changed = {'c','a','d','b','c','b','d'};
    // vector<int> cost = {7,2,1,3,6,1,7};
    Solution S;
    cout << S.minimumCost(source, target, original, changed, cost) << endl;
    return 0;
}