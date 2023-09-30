#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool in_time(vector<int>& piles, int k, int time){
        long ans = 0;
        for (auto i : piles) {
            ans += i / k + (i % k > 0);
            if (ans > time) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if (h < n) return -1;

        int max_pile = 0;
        for (auto i : piles) max_pile = max(max_pile, i);
        int min_pile = 1;
        while(min_pile < max_pile){
            int mid = min_pile + (max_pile - min_pile) / 2;
            // cout << min_pile << " " << mid << " " << max_pile << endl;
            if (in_time(piles, mid, h)) max_pile = mid;
            else min_pile = mid+1;
        }
        return max_pile;
    }
};

int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    // vector<int> piles = {30,11,23,4,20};
    // int h = 5;
    // vector<int> piles = {30,11,23,4,20};
    // int h = 6;
    Solution S;
    cout << S.minEatingSpeed(piles, h) << endl;
    return 0;
}