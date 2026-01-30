#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int inf = 1e9 + 7;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> matrix(26, vector<int>(26, inf));
        int k = changed.size();
        for (int i = 0; i < k; i++) matrix[original[i] - 'a'][changed[i] - 'a'] = min(matrix[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        for (int i = 0; i < 26; i++) matrix[i][i] = 0;
        for (int k = 0; k < 26; k++){
            for (int i = 0; i < 26; i++){
                for (int j = 0; j < 26; j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        long long ans = 0;
        int n = source.length();
        for (int i = 0; i < n; i++){
            long long c = matrix[source[i] - 'a'][target[i] - 'a'];
            if (c == inf) return -1;
            ans += c;
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
    // string source = "aaadbdcdac";
    // string target = "cdbabaddba";
    // vector<char> original = {'a','c','b','d','b','a','c'};
    // vector<char> changed = {'c','a','d','b','c','b','d'};
    // vector<int> cost = {7,2,1,3,6,1,7};
    Solution S;
    cout << S.minimumCost(source, target, original, changed, cost) << endl;
    return 0;
}