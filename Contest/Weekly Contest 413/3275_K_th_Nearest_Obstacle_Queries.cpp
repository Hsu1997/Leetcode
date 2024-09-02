#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        vector<int> result;
        for (auto i : queries){
            pq.push(abs(i[0]) + abs(i[1]));
            if (pq.size() > k) pq.pop();
            if (pq.size() < k) result.push_back(-1);
            else result.push_back(pq.top());
        }
        return result;
    }
};

int main(){
    vector<vector<int>> queries = {{1,2},{3,4},{2,3},{-3,0}};
    int k = 2;
    // vector<vector<int>> queries = {{5,5},{4,4},{3,3}};
    // int k = 1;
    Solution S;
    vector<int> ans = S.resultsArray(queries, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}