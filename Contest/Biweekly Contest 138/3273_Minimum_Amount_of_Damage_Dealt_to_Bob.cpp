#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct compare{
        bool operator()(const pair<double,pair<int,int>>& a, const pair<double,pair<int, int>>& b){
            if (a.first != b.first) return a.first < b.first;
            else return a.second.first > b.second.first;
        }
    };
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, compare> pq;
        long long acc = 0;
        long long ans = 0;
        for (int i = 0; i < damage.size(); i++){
            acc += damage[i];
            long long time = health[i] / power + (health[i] % power > 0);
            double ratio = (double)damage[i] / (double)time;
            pq.push({ratio, {time, i}});
        }
        while(!pq.empty()){
            double ratio = pq.top().first;
            int time = pq.top().second.first;
            int d = damage[pq.top().second.second];
            pq.pop();
            ans += round(acc * time);
            acc -= d;
        }
        return ans;
    }
};

int main(){
    int power = 4;
    vector<int> damage = {1,2,3,4};
    vector<int> health = {4,5,6,8};
    // int power = 1;
    // vector<int> damage = {1,1,1,1};
    // vector<int> health = {1,2,3,4};
    // int power = 8;
    // vector<int> damage = {40};
    // vector<int> health = {59};
    Solution S;
    cout << S.minDamage(power, damage, health) << endl;
    return 0;
}