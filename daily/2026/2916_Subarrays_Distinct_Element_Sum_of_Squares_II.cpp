#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class BIT{
public:
    int size;
    vector<long long> _tree1;
    vector<long long> _tree2;
    BIT(int n){
        size = n;
        _tree1.assign(n + 2, 0);
        _tree2.assign(n + 2, 0);
    }
    void add(int l, int r, int t){
        _add(l, t);
        _add(r + 1, -t);
    }
    long long query(int l, int r){
        return _query(r) - _query(l - 1);
    }
private:
    int _lowbit(int i) {return i & (-i);}
    void _add(int i, int t){
        i++;
        long long d = (i - 1) * t;
        while(i <= size){
            _tree1[i] += t;
            _tree2[i] += d;
            i += _lowbit(i);
        }
    }
    long long _query(int i){
        i++;
        if (i > size) i = size;
        long long res = 0;
        long long d = i;
        while(i > 0){
            res += d * _tree1[i] - _tree2[i];
            i -= _lowbit(i);
        }
        return res;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        long long cur = 0;
        long long mod = 1e9 + 7;
        BIT bit(n);
        unordered_map<int,int> lastest_seen;
        for (int i = 0; i < n; i++){
            int v = nums[i];
            int start = (lastest_seen.count(v)? lastest_seen[v] : -1) + 1;
            long long q = bit.query(start, i);
            cur = (cur + 2 * q + (i - start + 1)) % mod;
            res = (res + cur) % mod;
            bit.add(start, i, 1);
            lastest_seen[v] = i;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,1};
    // vector<int> nums = {2,2};
    Solution S;
    cout << S.sumCounts(nums) << endl;
    return 0;
}