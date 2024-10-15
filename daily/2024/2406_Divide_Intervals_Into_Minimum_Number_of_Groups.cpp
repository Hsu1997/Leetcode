#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), less<vector<int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto i : intervals){
            int start = i[0];
            int end = i[1];
            if (!pq.empty() && pq.top() < start) pq.pop();
            pq.push(end);
        }
        return pq.size();
    }
};

int main(){
    vector<vector<int>> intervals = {{5,10},{6,8},{1,5},{2,3},{1,10}};
    // vector<vector<int>> intervals = {{1,3},{5,6},{8,10},{11,13}};
    Solution S;
    cout << S.minGroups(intervals) << endl;
    return 0;
}