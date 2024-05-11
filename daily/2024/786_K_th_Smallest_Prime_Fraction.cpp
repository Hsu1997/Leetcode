#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> pq;
        for (int i = 0; i < n; i++) pq.push({double(arr[i]) / arr[n-1], {i, n-1}});
        while(--k){
            pair<int,int> cur = pq.top().second;
            // cout << "pop " << pq.top().first << " : (" << cur.first << "," << cur.second << ")" << endl;
            pq.pop();
            cur.second--;
            // cout << "push " << double(arr[cur.first]) / arr[cur.second] << " : (" << cur.first << "," << cur.second << ")" << endl;
            pq.push({double(arr[cur.first]) / arr[cur.second], {cur.first, cur.second}});
        }
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};

int main(){
    vector<int> arr = {1,2,3,5};
    int k = 3;
    // vector<int> arr = {1,7};
    // int k = 1;
    Solution S;
    vector<int> ans = S.kthSmallestPrimeFraction(arr, k);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}