#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int ans = 0;
        int left_empty_max = 0;
        for (int i = 0; i < n; i++){
            int left = (i == 0)? 0 : endTime[i-1];
            int right = (i == n-1)? eventTime : startTime[i+1];
            if (endTime[i] - startTime[i] <= left_empty_max) ans = max(ans, right - left);
            left_empty_max = max(left_empty_max, startTime[i] - left);
            ans = max(ans, right - left - (endTime[i] - startTime[i]));
        }
        int right_empty_max = 0;
        for (int i = n-1; i >= 0; i--){
            int left = (i == 0)? 0 : endTime[i-1];
            int right = (i == n-1)? eventTime : startTime[i+1];
            if (endTime[i] - startTime[i] <= right_empty_max) ans = max(ans, right - left);
            right_empty_max = max(right_empty_max, right - endTime[i]);
            ans = max(ans, right - left - (endTime[i] - startTime[i]));
        }
        return ans;
    }
};

int main(){
    int eventTime = 5;
    vector<int> startTime = {1,3};
    vector<int> endTime = {2,5};
    // int eventTime = 10;
    // vector<int> startTime = {0,7,9};
    // vector<int> endTime = {1,8,10};
    // int eventTime = 10;
    // vector<int> startTime = {0,3,7,9};
    // vector<int> endTime = {1,4,8,10};
    // int eventTime = 5;
    // vector<int> startTime = {0,1,2,3,4};
    // vector<int> endTime = {1,2,3,4,5};
    Solution S;
    cout << S.maxFreeTime(eventTime, startTime, endTime) << endl;
    return 0;
}