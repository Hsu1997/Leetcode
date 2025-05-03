#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool valid(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k){
        multiset<int> ms;
        for (int i = 0; i < k; i++) ms.insert(workers[i]);
        for (int i = k - 1; i >= 0; i--){
            if (*prev(ms.end()) >= tasks[i]) ms.erase(prev(ms.end()));
            else{
                if (pills == 0) return false;
                pills--;
                auto it = ms.lower_bound(tasks[i] - strength);
                if (it == ms.end()) return false;
                ms.erase(it);
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater());
        int left = 0;
        int right = min(tasks.size(), workers.size());
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (valid(tasks, workers, pills, strength, mid)){
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};

int main(){
    vector<int> tasks = {3,2,1};
    vector<int> workers = {0,3,3};
    int pills = 1;
    int strength = 1;
    // vector<int> tasks = {5,4};
    // vector<int> workers = {0,0,0};
    // int pills = 1;
    // int strength = 5;
    // vector<int> tasks = {10,15,30};
    // vector<int> workers = {0,10,10,10,10};
    // int pills = 3;
    // int strength = 10;
    // vector<int> tasks = {5,9,8,5,9};
    // vector<int> workers = {1,6,4,2,6};
    // int pills = 1;
    // int strength = 5;
    Solution S;
    cout << S.maxTaskAssign(tasks, workers, pills, strength) << endl;
    return 0;
}