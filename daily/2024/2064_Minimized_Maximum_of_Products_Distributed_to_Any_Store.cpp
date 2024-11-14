#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& quantities, int amount, int n){
        int count = 0;
        for (int i : quantities){
            count += i / amount + (i % amount > 0);
            if (count > n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int q = quantities.size();
        if (q > n) return -1;
        if (q == n) return *max_element(quantities.begin(), quantities.end());
        long long total = 0;
        for (int i : quantities) total += i;
        long long left = total / n + (total % n > 0);
        long long right = *max_element(quantities.begin(), quantities.end());
        long long ans = right;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if (check(quantities, mid, n)){
                ans = min(ans, mid);
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};

int main(){
    int n = 6;
    vector<int> quantities = {11,6};
    // int n = 7;
    // vector<int> quantities = {15,10,10};
    // int n = 1;
    // vector<int> quantities = {100000};
    // int n = 100000;
    // vector<int> quantities = {1};
    Solution S;
    cout << S.minimizedMaximum(n, quantities) << endl;
    return 0;
}