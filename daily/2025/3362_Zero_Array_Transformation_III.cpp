#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        };
        sort(queries.begin(), queries.end(), cmp);
        priority_queue<int, vector<int>, less<int>> candidate;
        priority_queue<int, vector<int>, greater<int>> minus;
        int n = nums.size();
        int q = 0;
        int curr = 0;
        for (int i = 0; i < n; i++){
            while(q < queries.size() && queries[q][0] == i){
                candidate.push(queries[q][1]);
                q++;
            }
            while(!minus.empty() && minus.top() < i){
                minus.pop();
                curr--;
            }
            while(curr < nums[i]){
                if (candidate.empty()) return -1;
                int temp = candidate.top();
                candidate.pop();
                if (temp < i) continue;
                minus.push(temp);
                curr++;
            }
        }
        return candidate.size();
    }
};

int main(){
    // vector<int> nums = {2,0,2};
    // vector<vector<int>> queries = {{0,2},{0,2},{1,1}};
    // vector<int> nums = {1,1,1,1};
    // vector<vector<int>> queries = {{1,3},{0,2},{1,3},{1,2}};
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> queries = {{0,3}};
    Solution S;
    cout << S.maxRemoval(nums, queries) << endl;
    return 0;
}