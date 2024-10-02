#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long acc(int i) {return ((long long)i + 1) * i / 2;}
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pair<long long, pair<int,int>>, vector<pair<long long, pair<int,int>>>, greater<pair<long long, pair<int,int>>>> pq;
        for (auto i : workerTimes){
            pq.push({(long long)i, {i, 1}});
        }
        long long time = -1;
        while(mountainHeight--){
            time = pq.top().first;
            auto [base, times] = pq.top().second;
            pq.pop();
            pq.push({acc(times+1) * base, {base, times+1}});
        }
        return time;
    }
};

int main(){
    int mountainHeight = 4;
    vector<int> workerTimes = {2,1,1};
    // int mountainHeight = 10;
    // vector<int> workerTimes = {3,2,2,4};
    // int mountainHeight = 5;
    // vector<int> workerTimes = {1};
    Solution S;
    cout << S.minNumberOfSeconds(mountainHeight, workerTimes) << endl;
    return 0;
}