#include <iostream>
#include <vector>

using namespace std;

class Fenwick{
public:
    Fenwick(int m){
        n = 1;
        while (n < m) n <<= 1;
        v.resize(n, 0);
    }
    void insert(int pos, int i){
        while (pos < n){
            v[pos] += i;
            pos += pos & -pos;
        }
    }
    long long query(int pos){
        int res = 0;
        while(pos > 0){
            res += v[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    long long period_query(int l, int r){
        return query(r) - query(l - 1);
    }
private:
    int n;
    vector<long long> v;
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        Fenwick F(200001);
        int cnt = 100000;
        F.insert(cnt, 1);
        long long ans = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == target) cnt++;
            else cnt--;
            ans += F.query(cnt - 1);
            F.insert(cnt, 1);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,2,3};
    int target = 2;
    // vector<int> nums = {1,1,1,1};
    // int target = 1;
    // vector<int> nums = {1,2,3};
    // int target = 4;
    Solution S;
    cout << S.countMajoritySubarrays(nums, target) << endl;
    return 0;
}