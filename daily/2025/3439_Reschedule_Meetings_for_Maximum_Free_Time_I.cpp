#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        startTime.push_back(eventTime);
        endTime.insert(endTime.begin(), 0);
        int n = startTime.size();
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < n; i++){
            curr += startTime[i] - endTime[i];
            if (i-k-1 >= 0) curr -= startTime[i-k-1] - endTime[i-k-1];
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main(){
    int eventTime = 5;
    int k = 1;
    vector<int> startTime = {1,3};
    vector<int> endTime = {2,5};
    // int eventTime = 10;
    // int k = 1;
    // vector<int> startTime = {0,2,9};
    // vector<int> endTime = {1,4,10};
    // int eventTime = 5;
    // int k = 2;
    // vector<int> startTime = {0,1,2,3,4};
    // vector<int> endTime = {1,2,3,4,5};
    // int eventTime = 21;
    // int k = 1;
    // vector<int> startTime = {7,10,16};
    // vector<int> endTime = {10,14,18};
    Solution S;
    cout << S.maxFreeTime(eventTime, k, startTime, endTime) << endl;
    return 0;
}