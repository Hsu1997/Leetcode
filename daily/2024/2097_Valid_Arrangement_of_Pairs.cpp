#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,queue<int>> adj;
        unordered_map<int,int> in, out;
        for (auto& pair : pairs){
            int start = pair[0];
            int end = pair[1];
            in[end]++;
            out[start]++;
            adj[start].push(end);
        }
        vector<int> result;
        function<void(int)> visit = [&](int node){
            while(!adj[node].empty()){
                int next = adj[node].front();
                adj[node].pop();
                visit(next);
            }
            result.push_back(node);
        };
        int start_node = -1;
        for (auto& n : out){
            int node = n.first;
            if (out[node] == in[node] + 1){
                start_node = node;
                break;
            }
        }
        if (start_node == -1) start_node = pairs[0][0];
        visit(start_node);
        reverse(result.begin(), result.end());
        vector<vector<int>> ans;
        int n = result.size();
        for (int i = 1; i < n; i++){
            ans.push_back({result[i-1], result[i]});
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> pairs = {{5,1},{4,5},{11,9},{9,4}};
    // vector<vector<int>> pairs = {{1,3},{3,2},{2,1}};
    // vector<vector<int>> pairs = {{1,2},{1,3},{2,1}};
    Solution S;
    vector<vector<int>> ans = S.validArrangement(pairs);
    for (auto i : ans){
        cout << "{" << i[0] << "," << i[1] << "} ";
    }
    cout << endl;
    return 0;
}