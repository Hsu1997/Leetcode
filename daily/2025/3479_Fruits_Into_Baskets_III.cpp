#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
public:
    int d;
    vector<int> t;

    SegmentTree(vector<int> nums){
        int n = nums.size();
        int l = 0;
        while(n){
            n >>= 1;
            l++;
        }
        d = 1 << l;
        t = vector<int>(d * 2, 0);
        for (int i = 0; i < nums.size(); i++){
            t[d + i] = nums[i];
        }
        for (int i = d - 1; i > 0; i--){
            t[i] = max(t[i * 2], t[i * 2 + 1]);
        }
    }

    void change(int pos, int val){
        pos += d;
        t[pos] = val;
        pos /= 2;
        while(pos > 0){
            t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
            pos /= 2;
        }
    }

    int find_leftmost_pos_greater_or_equal(int v){
        int pos = 1;
        while(pos < d){
            if (t[pos] < v) return -1;
            if (t[pos * 2] >= v) pos *= 2;
            else pos = pos * 2 + 1;
        }
        return pos - d;
    }
};


class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree ST(baskets);
        int ans = 0;
        for (int fruit : fruits){
            int p = ST.find_leftmost_pos_greater_or_equal(fruit);
            if (p == -1) ans++;
            else ST.change(p, 0);
        }
        return ans;
    }
};

int main(){
    vector<int> fruits = {4,2,5};
    vector<int> baskets = {3,5,4};
    // vector<int> fruits = {3,6,1};
    // vector<int> baskets = {6,4,7};
    Solution S;
    cout << S.numOfUnplacedFruits(fruits, baskets) << endl;
    return 0;
}