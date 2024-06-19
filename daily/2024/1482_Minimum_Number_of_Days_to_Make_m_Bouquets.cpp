#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool make_bouquets(vector<int>& bloomDay, int days, int m, int k){
        int temp = 0;
        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] <= days){
                temp++;
                if (temp == k) m--, temp = 0;
                if (m == 0) return true;
            }
            else temp = 0;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (double)m * k) return -1;
        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while(left < right){
            int mid = left + (right - left) / 2;
            if (make_bouquets(bloomDay, mid, m, k)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main(){
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;
    // vector<int> bloomDay = {1,10,3,10,2};
    // int m = 3;
    // int k = 2;
    // vector<int> bloomDay = {7,7,7,7,12,7,7};
    // int m = 2;
    // int k = 3;
    Solution S;
    cout << S.minDays(bloomDay, m, k) << endl;
    return 0;
}