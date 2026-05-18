#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, false);
        queue<int> que;
        que.push(start);
        visited[start] = true;
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            if (arr[curr] == 0) return true;
            if (curr - arr[curr] >= 0 && !visited[curr - arr[curr]]){
                que.push(curr - arr[curr]);
                visited[curr - arr[curr]] = true;
            }
            if (curr + arr[curr] < n && !visited[curr + arr[curr]]){
                que.push(curr + arr[curr]);
                visited[curr + arr[curr]] = true;
            }
        }
        return false;
    }
};

int main(){
    vector<int> arr = {4,2,3,0,3,1,2};
    int start = 5;
    // vector<int> arr = {4,2,3,0,3,1,2};
    // int start = 0;
    // vector<int> arr = {3,0,2,1,2};
    // int start = 2;
    Solution S;
    cout << S.canReach(arr, start) << endl;
    return 0;
}