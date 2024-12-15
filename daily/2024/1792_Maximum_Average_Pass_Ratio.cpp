#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double ans = 0;
        auto cmp = [](pair<int,int>& a, pair<int,int>& b){
            double ab = (double)a.first / a.second;
            double af = (double)(a.first+1) / (a.second+1);
            double bb = (double)b.first / b.second;
            double bf = (double)(b.first+1) / (b.second+1);
            return af - ab < bf - bb;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for (auto c : classes){
            int pass = c[0];
            int total = c[1];
            if (pass == total) ans++;
            else pq.push({pass, total});
        }
        for (int i = 0; i < extraStudents; i++){
            if (pq.empty()) break;
            auto curr = pq.top();
            pq.pop();
            pq.push({curr.first+1, curr.second+1});
        }
        while(!pq.empty()){
            ans += (double)pq.top().first / pq.top().second;
            pq.pop();
        }
        return ans / n;
    }
};

int main(){
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;
    // vector<vector<int>> classes = {{2,4},{3,9},{4,5},{2,10}};
    // int extraStudents = 4;
    Solution S;
    cout << S.maxAverageRatio(classes, extraStudents) << endl;
    return 0;
}