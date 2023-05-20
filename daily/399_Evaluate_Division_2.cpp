#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<pair<int,double>>> edges;
    double query(string i, string j, vector<vector<string>>& equations, vector<double>& values){
        unordered_map<string, bool> visited;
        visited[i] = true;
        double acc = 1.0;
        if (dfs(i, j, acc, visited, equations, values)) return acc;
        else return -1l;
    }
    
    bool dfs(string i, string j, double& acc, unordered_map<string, bool> visited, vector<vector<string>>& equations, vector<double>& values){
        // cout << "from " << i << " to " << j << ", acc = " << acc << endl;
        if (i == j) return true;
        visited[i] = true;
        // cout << i << " => true" << endl;
        for (int k = 0; k < equations.size(); k++){
            // cout << "condider " << equations[k][0] << " to " << equations[k][1] << endl;
            if (equations[k][0] == i && !visited[equations[k][1]]){
                acc *= values[k];
                if (dfs(equations[k][1], j, acc, visited, equations, values)) return true;
                acc /= values[k];
            }
        }
        visited[i] = false;
        // cout << i << " => false" << endl;
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> node;
        int n = equations.size();
        for (int i = 0; i < n; i++){
            equations.push_back({equations[i][1], equations[i][0]});
            values.push_back(1 / values[i]);
            node.insert(equations[i][0]);
            node.insert(equations[i][1]);
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++){
            if (!node.count(queries[i][0]) || !node.count(queries[i][1])) ans.push_back(-1);
            else{
                for (int k = 0; k < equations.size(); k++){
                    if (queries[i][0] == equations[k][0] && queries[i][1] == equations[k][1]){
                        ans.push_back(values[k]);
                        break;
                    }
                }
                if (ans.size() <= i) ans.push_back(query(queries[i][0], queries[i][1], equations, values));
            }
        }
        return ans;
    }
};

int main(){
    // vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    // vector<double> values = {2.0,3.0};
    // vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    // vector<vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    // vector<double> values = {1.5,2.5,5.0};
    // vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    // vector<vector<string>> equations = {{"a","e"},{"b","e"}};
    // vector<double> values = {4.0,3.0};
    // vector<vector<string>> queries = {{"a","b"},{"e","e"},{"x","x"}};
    vector<vector<string>> equations = {{"x1","x2"},{"x2","x3"},{"x1","x4"},{"x2","x5"}};
    vector<double> values = {3.0,0.5,3.4,5.6};
    vector<vector<string>> queries = {{"x2","x4"}};

    Solution S;
    vector<double> ans = S.calcEquation(equations, values, queries);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}