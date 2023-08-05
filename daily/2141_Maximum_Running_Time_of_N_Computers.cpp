#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long total_energy = 0;
        for (auto i : batteries) total_energy += i;
        long left = 1;
        long right = total_energy / n;
        
        while(left < right){
            long mid = right - (right - left) / 2;
            long consume = 0;
            for (long i : batteries) consume += min(i, mid);
            if (consume >= n * mid) left = mid;
            else right = mid-1;
        }
        return left;
    }
};

int main(){
    int n = 2;
    vector<int> batteries = {3,3,3};
    Solution S;
    cout << S.maxRunTime(n, batteries) << endl;
    return 0;
}