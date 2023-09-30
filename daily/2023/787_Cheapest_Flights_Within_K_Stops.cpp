#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> path(n);
        vector<int> cost(n, INT_MAX);
        for (int i = 0; i < flights.size(); i++){
            path[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        cost[src] = 0;
        for(int stop = 0; stop <= k; stop++){
            // for (auto i : cost) cout << i << " ";
            // cout << endl;
            vector<int> temp;
            for (auto i : cost) temp.push_back(i);
            for (int town = 0; town < n; town++){
                if (cost[town] != INT_MAX){
                    for (auto new_flight : path[town]){
                        temp[new_flight[0]] = min(temp[new_flight[0]], cost[town] + new_flight[1]);
                    }
                }
            }
            swap(cost, temp);
        }
        return (cost[dst] == INT_MAX)? -1 : cost[dst];
    }
};

int main(){
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;
    Solution S;
    cout << S.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}