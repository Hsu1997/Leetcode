#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool in_time(vector<int>& weights, int days, int capacity){
        int d = 1;
        int temp = capacity;
        for (int item : weights){
            if (temp >= item) temp -= item;
            else{
                temp = capacity - item;
                d++;
                if (d > days) return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0;
        int max_item = 0;
        for (auto item : weights){
            max_item = max(max_item, item);
            total += item;
        }
        int l = max(total/days + (total % days > 0), max_item);
        int r = total;
        while(l < r){
            int mid = (l+r)/2;
            if (in_time(weights, days, mid)) r = mid;
            else l = mid+1;
        }
        return l;
    }
};

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    // vector<int> weights = {3,2,2,4,1,4};
    // int days = 3;
    // vector<int> weights = {1,2,3,1,1};
    // int days = 4;
    Solution S;
    cout << S.shipWithinDays(weights, days) << endl;
    return 0;
}