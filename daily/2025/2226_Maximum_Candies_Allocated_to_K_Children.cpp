#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = 0;
        for (int i : candies) right += i;
        right /= k;
        long long ans = 0;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if (valid_allocation(candies, k, mid)){
                ans = max(ans, mid);
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
    bool valid_allocation(vector<int>& candies, long long k, long long amount){
        long long piles = 0;
        for (int candy : candies){
            piles += candy / amount;
            if (piles >= k) return true;
        }
        return false;
    }
};

int main(){
    vector<int> candies = {5,8,6};
    long long k = 3;
    // vector<int> candies = {2,5};
    // long long k = 11;
    Solution S;
    cout << S.maximumCandies(candies, k) << endl;
    return 0;
}