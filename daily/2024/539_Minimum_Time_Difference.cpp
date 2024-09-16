#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (string time : timePoints){
            times.push_back(stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2)));
        }
        sort(times.begin(), times.end());
        if (times.size() < 2) return -1;
        int ans = times[0] + 1440 - times.back();
        for (int i = 1; i < times.size(); i++){
            ans = min(ans, times[i] - times[i-1]);
        }
        return ans;
    }
};

int main(){
    vector<string> timePoints = {"23:59","00:00"};
    // vector<string> timePoints = {"00:00","23:59","00:00"};
    Solution S;
    cout << S.findMinDifference(timePoints) << endl;
    return 0;
}