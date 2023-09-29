#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool in_time(vector<int>& dist, int speed, double hour){
        double time = 0;
        for (int i = 0; i < dist.size()-1; i++){
            time += (dist[i] / speed);
            if (dist[i] % speed) time++;
            if (time > hour) return false;
        }
        time += ((double)dist.back() / speed);
        // cout << "need time = " << time << "/" << hour << endl;
        return (time > hour)? false : true;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size()-1 >= hour) return -1;
        int l = 1;
        int r = *max_element(dist.begin(), dist.end());
        r = max(r, (int)(dist.back() / (hour + 1 - dist.size())) + 1);
        while(l < r){
            int mid = l + (r - l) / 2;
            // cout << l << " " << r << " " << mid << endl;
            if (in_time(dist, mid, hour)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};

int main(){
    // vector<int> dist = {1,3,2};
    // double hour = 6;
    // double hour = 2.7;
    // double hour = 1.9;
    vector<int> dist = {1,1,100000};
    double hour = 2.01;
    Solution S;
    cout << S.minSpeedOnTime(dist, hour) << endl;
    return 0;
}