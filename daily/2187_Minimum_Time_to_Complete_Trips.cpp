#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool in_time(vector<int>& time, long long totalTrips, long long k){
        long long ans = 0;
        for (auto i : time){
            ans += k / i;
            if (ans >= totalTrips) return true;
        }
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int min_time = INT_MAX;
        for(auto i : time) min_time = min(min_time, i);
        long long r = (long long)min_time * (long long)totalTrips;
        long long l = 0;
        while(l < r){
            long long mid = l + (r-l)/2;
            if (in_time(time, totalTrips, mid)) r = mid;
            else l = mid+1;
        }
        return r;
    }
};

int main(){
    vector<int> time = {1,2,3};
    int totalTrips = 5;
    // vector<int> time = {2};
    // int totalTrips = 1;
    Solution S;
    cout << S.minimumTime(time, totalTrips) << endl;
    return 0;
}