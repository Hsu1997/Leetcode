#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map< string, vector< pair<string, double> > > edge;
    unordered_map<string, bool> visited;
    double ans;

    bool dfs(string a, string b, double accumulated){
        if (a == b && edge.find(a) != edge.end()){
            ans = accumulated;
            return true;
        }
        
        visited[a] = true;
        // it : {neighbor, value}
        for (auto it : edge[a]){
            if (!visited[it.first]){
                // cout << "original acc = " << accumulated << " ";
                accumulated *= it.second;
                // cout << "look " << a << " to " << it.first << ", acc = " << accumulated << endl;
                if (dfs(it.first, b, accumulated)){
                    visited[a] = false;
                    return true;
                }
                accumulated /= it.second;
            }
        }
        visited[a] = false;

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++){
            string s1 = equations[i][0];
            string s2 = equations[i][1];
            edge[s1].push_back({s2,values[i]});
            edge[s2].push_back({s1,1 / values[i]});
            visited[s1] = false;
            visited[s2] = false;
        }

        vector<double> all_ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++){
            // cout << "now is " << i << " term : ";
            string s1 = queries[i][0];
            string s2 = queries[i][1];
            // cout << "dfs(" << s1 << "," << s2 << ")" << endl;
            if (dfs(s1, s2, 1))all_ans[i] = ans;
            else all_ans[i] = -1;
            // cout << all_ans[i] << endl;
        }
        return all_ans;
    }
};

int main(){
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    Solution S;
    // S.calcEquation(equations, values, queries);
    for (double i : S.calcEquation(equations, values, queries)) cout << i << " ";
    cout << endl;
    return 0;
}