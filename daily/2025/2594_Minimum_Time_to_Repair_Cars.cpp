#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using ll = long long;
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        unordered_map<int,int> count;
        for (int rank : ranks) count[rank]++;
        auto compare = [](vector<ll>& a, vector<ll>& b){
            return a[0] > b[0];
        };
        priority_queue<vector<ll>, vector<vector<ll>>, decltype(compare)> pq(compare);
        // [time, rank, per_repair_count, same_rank_count]
        for (auto [r, c] : count) pq.push({r, r, 1, c});
        ll ans = 0;
        while(cars > 0){
            auto curr = pq.top();
            pq.pop();
            ans = curr[0];
            int rank = curr[1];
            ll n = curr[2];
            cars -= curr[3];
            n++;
            pq.push({rank * n * n, rank, n, curr[3]});
        }
        return ans;
    }
};

int main(){
    vector<int> ranks = {4,2,3,1};
    int cars = 10;
    // vector<int> ranks = {5,1,8};
    // int cars = 6;
    // vector<int> ranks = {3,3,1,2,1,1,3,2,1};
    // int cars = 58;
    Solution S;
    cout << S.repairCars(ranks, cars) << endl;
    return 0;
}