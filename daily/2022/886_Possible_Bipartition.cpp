#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> u;

    int find(int n){ return (u[n] == n)? u[n] : u[n] = find(u[n]);}

    void combine(int i, int j){u[find(j)] = find(i);}

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        u = vector<int>(n+1);
        for (int i = 0; i <= n; i++) u[i] = i;

        vector<vector<int>> m(n+1);
        for (auto i : dislikes){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        // for (auto i : m){
        //     for (auto j : i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        
        for (int i = 1; i <= n; i++){
            vector<int>& temp = m[i];
            if (temp.size() == 0) continue;
            for (int j = 0; j < temp.size(); j++){
                if (find(i) == find(temp[j])) return false;
                combine(temp[0], temp[j]);
            }
        }
        // for (auto i : u) cout << i << " ";
        // cout << endl;

        return true;
    }
};

int main(){
    // int n = 4;
    // vector<vector<int>> dislikes = {{1,2},{1,3},{2,4}};
    // int n = 3;
    // vector<vector<int>> dislikes = {{1,2},{1,3},{2,3}};
    // int n = 5;
    // vector<vector<int>> dislikes = {{1,2},{2,3},{3,4},{4,5},{1,5}};
    int n = 10;
    vector<vector<int>> dislikes = {{4,7},{4,8},{5,6},{1,6},{3,7},{2,5},{5,8},{1,2},{4,9},{6,10},{8,10},{3,6},{2,10},{9,10},{3,9},{2,3},{1,9},{4,6},{5,7},{3,8},{1,8},{1,7},{2,4}};
    Solution S;
    cout << S.possibleBipartition(n, dislikes) << endl;
    return 0;
}