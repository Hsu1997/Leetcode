#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    long long currSum;
    void adjust(multiset<int>& st1, multiset<int>& st2, int s){
        while(st1.size() > s){
            auto M = prev(st1.end());
            st2.insert(*M);
            currSum -= 1LL * *M;
            st1.erase(M);
        }
        while(st1.size() < s && st2.size() > 0){
            st1.insert(*st2.begin());
            currSum += 1LL * *st2.begin();
            st2.erase(st2.begin());
        }
    }
    void add(multiset<int>& st1, multiset<int>& st2, int x, int s){
        st1.insert(x);
        currSum += x;
        adjust(st1, st2, s);
    }
    void del(multiset<int>& st1, multiset<int>& st2, int x, int s){
        auto it = st1.find(x);
        if (it != st1.end()){
            currSum -= *it;
            st1.erase(it);
        }
        else st2.erase(st2.find(x));
        adjust(st1, st2, s);
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {
        currSum = 0;
        int n = nums.size();
        multiset<int> st1;
        multiset<int> st2;
        for (int i = 1; i < k; i++){
            st1.insert(nums[i]);
            currSum += 1LL * nums[i];
        }
        long long ans = currSum;
        for (int i = k; i < n; i++){
            int d = i - dist - 1;
            if (d > 0) del(st1, st2, nums[d], k - 1);
            add(st1, st2, nums[i], k - 1);
            ans = min(ans, currSum);
        }
        return ans + nums[0];
    }
};

int main(){
    vector<int> nums = {1,3,2,6,4,2};
    int k = 3;
    int dist = 3;
    // vector<int> nums = {10,1,2,2,2,1};
    // int k = 4;
    // int dist = 3;
    // vector<int> nums = {10,8,18,9};
    // int k = 3;
    // int dist = 1;
    Solution S;
    cout << S.minimumCost(nums, k, dist) << endl;
    return 0;
}