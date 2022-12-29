#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static bool mycompare(vector<int>& a,vector<int>& b){
        if (a[0] != b[0]) return a < b;
        else return a[2] < b[2];
    }

    class my_compare{
    public:
        bool operator()(vector<int>& a, vector<int>& b){
            if (a[1] != b[1]) return a[1] > b[1];
            else return a[2] > b[2];
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        for (int i = 0; i < tasks.size(); i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), mycompare);
        // for (auto i : tasks){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        long now_time = tasks[0][0];
        int now_task = 1;
        priority_queue<vector<int>, vector<vector<int>>, my_compare> pq;
        pq.push(tasks[0]);
        // cout << "now_time = " << now_time << ", push 0" << endl;
        while(!pq.empty() || now_task < tasks.size()){
            if (pq.empty() && now_time < tasks[now_task][0]) now_time = tasks[now_task][0];
            while(now_task < tasks.size() && tasks[now_task][0] <= now_time){
                // cout << "now_time = " << now_time << ", push " << now_task << endl;
                pq.push(tasks[now_task++]);
            }
            vector<int> temp = pq.top();
            pq.pop();
            ans.push_back(temp[2]);
            now_time += temp[1];
            // cout << "pick up " << temp[2] << ", and now_time become " << now_time << endl;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> tasks = {{1,2},{2,4},{3,2},{4,1}};
    // vector<vector<int>> tasks = {{7,10},{7,12},{7,5},{7,4},{7,2}};
    Solution S;
    vector<int> ans = S.getOrder(tasks);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}