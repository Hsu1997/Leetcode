#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int assign_job(vector<pair<int,int>>& job, int ability){
        if (ability >= job.back().first) return job.back().second;
        if (ability < job[0].first) return 0;
        int left = 0;
        int right = job.size() - 1;
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            if (job[mid].first <= ability) left = mid;
            else right = mid - 1;
        }
        return job[left].second;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> job;
        int j = difficulty.size();
        for (int i = 0; i < j; i++) job.push_back({difficulty[i], profit[i]});
        sort(job.begin(), job.end());
        vector<pair<int,int>> sorted_job;
        sorted_job.push_back(job[0]);
        for (int i = 1; i < j; i++){
            if (job[i].second > sorted_job.back().second) sorted_job.push_back(job[i]);
        }
        int ans = 0;
        for (int i = 0; i < worker.size(); i++){
            ans += assign_job(sorted_job, worker[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> difficulty = {2,4,6,8,10};
    vector<int> profit = {10,20,30,40,50};
    vector<int> worker = {4,5,6,7};
    // vector<int> difficulty = {85,47,57};
    // vector<int> profit = {24,66,99};
    // vector<int> worker = {40,25,25};
    // vector<int> difficulty = {68,35,52,47,86};
    // vector<int> profit = {67,17,1,81,3};
    // vector<int> worker = {92,10,85,84,82};
    Solution S;
    cout << S.maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}