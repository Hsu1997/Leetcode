#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int production;
    long long count[5] = {0};
    Node() : production(1) {};
    Node(int val){
        production = val;
        count[val]++;
    }
};

class SegmentTree{
public:
    int n, s, k;
    vector<Node> tree;
    SegmentTree(vector<int>& nums, int k){
        this->k = k;
        n = nums.size();
        s = 1;
        while(s < n) s <<= 1;
        tree = vector<Node>(s * 2);
        for (int i = 0; i < n; i++){
            nums[i] %= k;
            tree[s + i] = Node(nums[i]);
        }
        for (int i = s - 1; i > 0; i--){
            tree[i] = combine(tree[i*2], tree[i*2+1]);
        }
    }
    Node combine(Node& a, Node& b){
        Node curr = Node();
        curr.production = (a.production * b.production) % k;
        for (int i = 0; i < 5; i++){
            curr.count[i] += a.count[i];
            curr.count[(a.production * i) % k] += b.count[i];
        }
        return curr;
    }
    void update(int idx, int val){
        idx += s;
        tree[idx] = Node(val);
        idx /= 2;
        while(idx){
            tree[idx] = combine(tree[idx*2], tree[idx*2+1]);
            idx /= 2;
        }
    }
    Node query(int l, int r){
        Node resL;
        Node resR;
        l += s;
        r += s;
        while(l <= r && l > 0 && r > 0){
            if (l % 2 == 1){
                resL = combine(resL, tree[l]);
                l++;
            }
            if (r % 2 == 0){
                resR = combine(tree[r], resR);
                r--;
            }
            l /= 2, r /= 2;
        }
        return combine(resL, resR);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> ans(q);
        SegmentTree S(nums, k);
        for (int query = 0; query < q; query++){
            int pos = queries[query][0];
            int val = queries[query][1] % k;
            int start = queries[query][2];
            int x = queries[query][3];
            S.update(pos, val);
            Node curr = S.query(start, n - 1);
            ans[query] = curr.count[x];
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    int k = 3;
    vector<vector<int>> queries = {{2,2,0,2},{3,3,3,0},{0,1,0,1}};
    // vector<int> nums = {1,2,4,8,16,32};
    // int k = 4;
    // vector<vector<int>> queries = {{0,2,0,2},{0,2,0,1}};
    // vector<int> nums = {1,1,2,1,1};
    // int k = 2;
    // vector<vector<int>> queries = {{2,1,0,1}};
    Solution S;
    vector<int> ans = S.resultArray(nums, k, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}