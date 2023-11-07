#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans = 1;
        int time = 1;
        int n = dist.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) pq.push(dist[i]/speed[i] + (dist[i] % speed[i] > 0));
        pq.pop();
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            if (temp <= time) return ans;
            ans++, time++;
        }
        return n;
    }
};

int main(){
    vector<int> dist = {1,3,4};
    vector<int> speed = {1,1,1};
    // vector<int> dist = {1,1,2,3};
    // vector<int> speed = {1,1,1,1};
    // vector<int> dist = {3,2,4};
    // vector<int> speed = {5,3,2};
    // vector<int> dist = {3,5,7,4,5};
    // vector<int> speed = {2,3,6,3,2};
    Solution S;
    cout << S.eliminateMaximum(dist, speed) << endl;
    return 0;
}