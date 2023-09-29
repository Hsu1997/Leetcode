#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct edge{
        int destination;
        int distance;
        edge* next;
        edge(int dest, int dis, edge* e) : destination(dest), distance(dis), next(e){}
    };

    int minScore(int n, vector<vector<int>>& roads) {
        vector<edge*> e(n+1, nullptr);
        for (auto i : roads){
            if (!e[i[0]]) e[i[0]] = new edge(i[1], i[2], nullptr);
            else e[i[0]] = new edge(i[1],i[2],e[i[0]]);
            e[i[1]] = new edge(i[0],i[2],e[i[1]]);
        }
        // int k = 0;
        // for (auto i : e){
        //     edge* temp = i;
        //     cout << k++ << endl;
        //     while(temp){
        //         cout << "(" << temp->destination << ", " << temp->distance << ") ";
        //         temp = temp->next;
        //     }
        //     cout << endl;
        // }

        vector<bool> visited(n+1);
        int ans = INT_MAX;
        queue<int> que;
        que.push(1);
        visited[1] = true;
        while(!que.empty()){
            int temp = que.front();
            que.pop();
            // cout << endl << "now visited node " << temp << " : ";
            if (!e[temp]) continue;
            edge* temp_e = e[temp];
            
            
            while(temp_e){
                // cout << temp_e->destination << " ";
                if (!visited[temp_e->destination]){
                    // cout << "-> push ";
                    que.push(temp_e->destination);
                    visited[temp_e->destination] = true;
                }
                ans = min(ans, temp_e->distance);
                temp_e = temp_e->next;
            }
        }
        // cout << endl;
        return ans;
    }
};

int main(){
    // int n = 4;
    // vector<vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    // vector<vector<int>> roads = {{1,2,2},{1,3,4},{3,4,7}};
    int n = 14;
    vector<vector<int>> roads = {{2,9,2308},{2,5,2150},{12,3,4944},{13,5,5462},{2,10,2187},{2,12,8132},{2,13,3666},{4,14,3019},{2,4,6759},{2,14,9869},{1,10,8147},{3,4,7971},{9,13,8026},{5,12,9982},{10,9,6459}};
    // ans = 2510
    Solution S;
    cout << S.minScore(n, roads) << endl;
    return 0;
}