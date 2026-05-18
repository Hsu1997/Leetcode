#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> m;
        for (int i = 0; i < n; i++) m[arr[i]].push_back(i);
        int steps = 0;
        vector<int> candidate;
        vector<bool> visited(n, false);
        candidate.push_back(0);
        while(!candidate.empty()){
            vector<int> temp;
            for (int i : candidate){
                if (i == n-1) return steps;
                if (i-1 >= 0 && !visited[i-1]){
                    temp.push_back(i-1);
                    visited[i-1] = true;
                }
                if (i+1 < n && !visited[i+1]){
                    temp.push_back(i+1);
                    visited[i+1] = true;
                }
                if (m.find(arr[i]) != m.end()){
                    for (int j : m[arr[i]]){
                        if (!visited[j]){
                            visited[j] = true;
                            temp.push_back(j);
                        }
                    }
                    m.erase(arr[i]);
                }
            }
            candidate = temp;
            steps++;
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    // vector<int> arr = {7};
    // vector<int> arr = {7,6,9,6,9,6,9,7};
    Solution S;
    cout << S.minJumps(arr) << endl;
    return 0;
}