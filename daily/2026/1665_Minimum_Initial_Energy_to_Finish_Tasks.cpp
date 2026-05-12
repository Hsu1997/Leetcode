#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool valid(vector<vector<int>>& tasks, int energy){
        for (auto& task : tasks){
            if (energy < task[1]) return false;
            energy -= task[0];
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        auto cmp = [](const vector<int>& t1, const vector<int>& t2){
            return t1[1] - t1[0] > t2[1] - t2[0];
        };
        sort(tasks.begin(), tasks.end(), cmp);
        int totalCost = 0;
        int maxLimit = 0;
        for (auto& task : tasks){
            totalCost += task[0];
            maxLimit = max(maxLimit, task[1]);
        }
        int right = maxLimit + totalCost;
        int left = maxLimit;
        while(right > left){
            int mid = left + (right - left) / 2;
            if (valid(tasks, mid)) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};

int main(){
    vector<vector<int>> tasks = {{1,2},{2,4},{4,8}};
    // vector<vector<int>> tasks = {{1,3},{2,4},{10,11},{10,12},{8,9}};
    // vector<vector<int>> tasks = {{1,7},{2,8},{3,9},{4,10},{5,11},{6,12}};
    Solution S;
    cout << S.minimumEffort(tasks) << endl;
    return 0;
}