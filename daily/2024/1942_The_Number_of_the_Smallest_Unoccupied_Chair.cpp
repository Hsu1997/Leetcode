#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target = times[targetFriend][0];
        sort(times.begin(), times.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        int next = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        priority_queue<int, vector<int>, greater<int>> chair;
        for (int i = 0; i < times.size(); i++){
            int start = times[i][0];
            int end = times[i][1];
            // cout << start << ", " << end << " : ";
            while(!pq.empty() && start >= pq.top().first){
                chair.push(pq.top().second);
                pq.pop();
            }
            int c;
            if (chair.empty()) c = next++;
            else{
                c = chair.top();
                chair.pop();
            }
            pq.push({end, c});
            // cout << c << endl;
            if (start == target) return c;
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> times = {{1,4},{2,3},{4,6}};
    int targetFriend = 1;
    // vector<vector<int>> times = {{3,10},{1,5},{2,6}};
    // int targetFriend = 0;
    Solution S;
    cout << S.smallestChair(times, targetFriend) << endl;
    return 0;
}