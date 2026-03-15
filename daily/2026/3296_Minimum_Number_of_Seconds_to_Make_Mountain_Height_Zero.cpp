#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans = LLONG_MAX;
        int maxWorkerTimes = *max_element(workerTimes.begin(), workerTimes.end());
        long long l = 1;
        long long r = (long long)maxWorkerTimes * mountainHeight * (mountainHeight + 1) / 2;
        while(l <= r){
            long long mid = (l + r) / 2;
            long long cnt = 0;
            for (int t : workerTimes){
                long long work = mid / t;
                long long k = (-1 + sqrt(1 + 8 * work)) / 2;
                cnt += k;
            }
            if (cnt >= mountainHeight){
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};

int main(){
    int mountainHeight = 4;
    vector<int> workerTimes = {2,1,1};
    // int mountainHeight = 10;
    // vector<int> workerTimes = {3,2,2,4};
    // int mountainHeight = 5;
    // vector<int> workerTimes = {1};
    Solution S;
    cout << S.minNumberOfSeconds(mountainHeight, workerTimes) << endl;
    return 0;
}