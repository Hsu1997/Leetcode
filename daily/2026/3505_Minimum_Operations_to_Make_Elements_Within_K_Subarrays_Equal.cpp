#include <iostream>
#include <vector>
#include <set>

using namespace std;

class sortedMedian{
public:
    sortedMedian(int _x) : x(_x) {}

    int get(){return *hi.begin();}
    int get_lo_size(){return lo.size();}
    int get_hi_size(){return hi.size();}
    long long get_lo_sum(){return sum1;}
    long long get_hi_sum(){return sum2;}

    void bal(){
        while(lo.size() > hi.size()){
            int curr = *lo.begin();
            sum1 -= curr;
            sum2 += curr;
            lo.erase(lo.find(curr));
            hi.insert(curr);
        }
        while(lo.size() + 1 < hi.size()){
            int curr = *hi.begin();
            sum1 += curr;
            sum2 -= curr;
            hi.erase(hi.find(curr));
            lo.insert(curr);
        }
    }

    void add(int v){
        if (hi.empty() || v >= get()){
            sum2 += v;
            hi.insert(v);
        }
        else{
            sum1 += v;
            lo.insert(v);
        }
        bal();
    }

    void del(int v){
        int m = get();
        if (v < m){
            sum1 -= v;
            lo.erase(lo.find(v));
        }
        else{
            sum2 -= v;
            hi.erase(hi.find(v));
        }
        bal();
    }

private:
    int x;
    multiset<int, greater<int>> lo;
    multiset<int> hi;
    long long sum1 = 0;
    long long sum2 = 0;
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> oper(n, 0);
        sortedMedian SM(x);
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            SM.add(curr);
            if (i - x >= 0){
                int curr_del = nums[i - x];
                SM.del(curr_del);
            }
            long long med = SM.get();
            if (i >= x - 1){
                long long op = med * SM.get_lo_size() - SM.get_lo_sum() + SM.get_hi_sum() - med * SM.get_hi_size();
                oper[i] = op;
            }
        }
        vector<long long> dp(n, 0);
        for (int j = 1; j <= k; j++){
            int start = j * x - 1;
            vector<long long> res(n, -1);
            for (int i = start; i < n; i++){
                long long currop = oper[i];
                res[i] = currop + ((i - x >= 0)? dp[i - x] : 0);
                if (i > 0 && res[i - 1] >= 0) res[i] = min(res[i], res[i-1]);
            }
            swap(dp, res);
        }
        return dp[n - 1];
    }
};

int main(){
    vector<int> nums = {5,-2,1,3,7,3,6,4,-1};
    int x = 3;
    int k = 2;
    // vector<int> nums = {9,-2,-2,-2,1,5};
    // int x = 2;
    // int k = 2;
    Solution S;
    cout << S.minOperations(nums, x, k) << endl;
    return 0;
}