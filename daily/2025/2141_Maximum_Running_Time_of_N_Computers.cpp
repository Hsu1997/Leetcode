#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool valid(int n, vector<int>& batteries, long long time){
        long long running = 0;
        for (long long i : batteries){
            running += min(i, time);
            if (running >= time * n) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (int i : batteries) total += i;
        long long low = 0;
        long long high = total / n;
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if (valid(n, batteries, mid)){
                ans = max(ans, mid);
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};

int main(){
    int n = 2;
    vector<int> batteries = {3,3,3};
    // int n = 2;
    // vector<int> batteries = {1,1,1,1};
    Solution S;
    cout << S.maxRunTime(n, batteries) << endl;
    return 0;
}