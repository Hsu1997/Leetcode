#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b){return a[2] < b[2];});
        vector<int> know(n, 0);
        know[0] = 1;
        know[firstPerson] = 1;
        int m = meetings.size();
        int ptr = 0;
        while(ptr < m){
            int t = meetings[ptr][2];
            unordered_map<int, vector<int>> graph;
            unordered_set<int> visited;
            queue<int> que;
            while(ptr < m && meetings[ptr][2] == t){
                int n1 = meetings[ptr][0];
                int n2 = meetings[ptr][1];
                graph[n1].push_back(n2);
                graph[n2].push_back(n1);
                if (know[n1] == 1 && visited.find(n1) == visited.end()){
                    visited.insert(n1);
                    que.push(n1);
                }
                if (know[n2] == 1 && visited.find(n2) == visited.end()){
                    visited.insert(n2);
                    que.push(n2);
                }
                ptr++;
            }
            while(!que.empty()){
                int curr = que.front();
                que.pop();
                know[curr] = 1;
                visited.insert(curr);
                for (int neighbor : graph[curr]){
                    if (visited.find(neighbor) == visited.end()){
                        visited.insert(neighbor);
                        que.push(neighbor);
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) if (know[i] == 1) ans.push_back(i);
        return ans;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> meetings = {{1,2,5},{2,3,8},{1,5,10}};
    int firstPerson = 1;
    // int n = 4;
    // vector<vector<int>> meetings = {{3,1,3},{1,2,2},{0,3,3}};
    // int firstPerson = 3;
    // int n = 5;
    // vector<vector<int>> meetings = {{3,4,2},{1,2,1},{2,3,1}};
    // int firstPerson = 1;
    // int n = 6;
    // vector<vector<int>> meetings = {{0,2,1},{1,3,1},{4,5,1}};
    // int firstPerson = 1;
    Solution S;
    vector<int> ans = S.findAllPeople(n, meetings, firstPerson);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}