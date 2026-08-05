#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (auto& e : invocations){
            graph[e[0]].push_back(e[1]);
        }
        unordered_set<int> suspicious;
        suspicious.insert(k);
        queue<int> que;
        que.push(k);
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for (int neighbor : graph[curr]){
                if (suspicious.find(neighbor) == suspicious.end()){
                    suspicious.insert(neighbor);
                    que.push(neighbor);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (suspicious.find(i) == suspicious.end()){
                for (int neighbor : graph[i]){
                    if (suspicious.find(neighbor) != suspicious.end()){
                        ans.resize(n);
                        iota(ans.begin(), ans.end(), 0);
                        return ans;
                    }
                }
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(){
    int n = 4;
    int k = 1;
    vector<vector<int>> invocations = {{1,2},{0,1},{3,2}};
    // int n = 5;
    // int k = 0;
    // vector<vector<int>> invocations = {{1,2},{0,2},{0,1},{3,4}};
    // int n = 3;
    // int k = 2;
    // vector<vector<int>> invocations = {{1,2},{0,1},{2,0}};
    Solution S;
    vector<int> ans = S.remainingMethods(n, k, invocations);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}