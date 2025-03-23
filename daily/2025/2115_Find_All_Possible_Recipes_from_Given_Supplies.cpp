#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<int> indegree(n);
        unordered_map<string,int> recipeToIndex;
        unordered_set<string> already_have;
        for (string s : supplies) already_have.insert(s);
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) recipeToIndex[recipes[i]] = i;
        for (int i = 0; i < n; i++){
            for (string ingredient : ingredients[i]){
                if (recipeToIndex.find(ingredient) != recipeToIndex.end()){
                    graph[recipeToIndex[ingredient]].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<int> que;
        for (int i = 0; i < n; i++) if (indegree[i] == 0) que.push(i);
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            bool valid = true;
            for (string need : ingredients[curr]){
                if (already_have.find(need) == already_have.end()){
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            already_have.insert(recipes[curr]);
            for (int neighbor : graph[curr]){
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) que.push(neighbor);
            }
        }
        vector<string> ans;
        for (string s : recipes) if (already_have.find(s) != already_have.end()) ans.push_back(s);
        return ans;
    }
};

int main(){
    vector<string> recipes = {"bread"};
    vector<vector<string>> ingredients = {{"yeast","flour"}};
    vector<string> supplies = {"yeast","flour","corn"};
    // vector<string> recipes = {"bread","sandwich"};
    // vector<vector<string>> ingredients = {{"yeast","flour"},{"bread","meat"}};
    // vector<string> supplies = {"yeast","flour","meat"};
    // vector<string> recipes = {"bread","sandwich","burger"};
    // vector<vector<string>> ingredients = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};
    // vector<string> supplies = {"yeast","flour","meat"};
    Solution S;
    vector<string> ans = S.findAllRecipes(recipes, ingredients, supplies);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}