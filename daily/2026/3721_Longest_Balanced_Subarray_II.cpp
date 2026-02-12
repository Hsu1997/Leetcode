#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct LazyTag{
    int toAdd = 0;

    LazyTag() {};
    LazyTag(int x) : toAdd(x) {};

    bool hasTag() const { return toAdd != 0; }
    void clear(){ toAdd = 0; }

    LazyTag& operator +=(const LazyTag& other){
        this->toAdd += other.toAdd;
        return *this;
    }
};

struct SegmentTreeNode{
    int minValue;
    int maxValue;
    LazyTag lazyTag;
    SegmentTreeNode() {};
    SegmentTreeNode(int x) : minValue(x), maxValue(x) {};
};

class SegmentTree{
public:
    int n;
    vector<SegmentTreeNode> tree;
    SegmentTree(const vector<int>& nodes){
        n = nodes.size();
        tree.resize(4 * n + 1);
        buildTree(nodes, 1, n, 1);
    }

    void periodAdd(int start, int end, int val){
        LazyTag t(val);
        periodUpdate(start, end, t, 1, n, 1);
    }

    int findLastZero(int start){
        if (start > n) return -1;
        return find(start, n, 0, 1, n, 1);
    }
private:
    void buildTree(const vector<int>& nodes, int start, int end, int nodeIdx){
        if (start == end){
            tree[nodeIdx] = SegmentTreeNode(nodes[start - 1]);
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(nodes, start, mid, nodeIdx * 2);
        buildTree(nodes, mid + 1, end, nodeIdx * 2 + 1);
        pushup(nodeIdx);
    }
    void pushup(int nodeIdx){
        tree[nodeIdx].minValue = min(tree[nodeIdx * 2].minValue, tree[nodeIdx * 2 + 1].minValue);
        tree[nodeIdx].maxValue = max(tree[nodeIdx * 2].maxValue, tree[nodeIdx * 2 + 1].maxValue);
    }
    void pushdown(int nodeIdx){
        // refresh all node under current node
        if (tree[nodeIdx].lazyTag.hasTag()){
            LazyTag tag = tree[nodeIdx].lazyTag;
            applyTag(tag, nodeIdx * 2);
            applyTag(tag, nodeIdx * 2 + 1);
            tree[nodeIdx].lazyTag.clear();
        }
    }
    void applyTag(const LazyTag& t, int nodeIdx){
        tree[nodeIdx].minValue += t.toAdd;
        tree[nodeIdx].maxValue += t.toAdd;
        tree[nodeIdx].lazyTag += t;
    }
    void periodUpdate(int start, int end, const LazyTag& t, int currNodeLeft, int currNodeRight, int nodeIdx){
        if (start <= currNodeLeft && currNodeRight <= end){
            applyTag(t, nodeIdx);
            return;
        }
        pushdown(nodeIdx);
        int mid = currNodeLeft + (currNodeRight - currNodeLeft) / 2;
        if (start <= mid) periodUpdate(start, end, t, currNodeLeft, mid, nodeIdx * 2);
        if (end >= mid + 1) periodUpdate(start, end, t, mid + 1, currNodeRight, nodeIdx * 2 + 1);
        pushup(nodeIdx);
    }
    int find(int start, int end, int val, int currNodeLeft, int currNodeRight, int nodeIdx){
        // not find val (any interval in which max and min contain val is guaranteed to contain val in this interval)
        if (tree[nodeIdx].minValue > val || tree[nodeIdx].maxValue < val) return -1;
        if (currNodeLeft == currNodeRight) return currNodeLeft;
        pushdown(nodeIdx);
        int mid = currNodeLeft + (currNodeRight - currNodeLeft) / 2;
        if (end >= mid + 1){
            int res = find(start, end, val, mid + 1, currNodeRight, nodeIdx * 2 + 1);
            if (res != -1) return res;
        }
        if (start <= mid && currNodeLeft <= end){
            return find(start, end, val, currNodeLeft, mid, nodeIdx * 2);
        }
        return -1;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, queue<int>> m;
        auto sgn = [](int x){ return (x % 2) == 0? 1 : -1; };
        vector<int> prefixSum(n, 0);
        prefixSum[0] = sgn(nums[0]);
        m[nums[0]].push(1);
        for (int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1];
            auto& latest = m[nums[i]];
            if (latest.empty()){
                prefixSum[i] += sgn(nums[i]);
            }
            latest.push(i + 1);
        }
        SegmentTree seg(prefixSum);
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, seg.findLastZero(i + 1 + ans) - i);
            int nextPos = n + 1;
            m[nums[i]].pop();
            // idx in map already convert to tree idx(+1)
            if (!m[nums[i]].empty()) nextPos = m[nums[i]].front();
            seg.periodAdd(i + 1, nextPos - 1, -sgn(nums[i]));
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,5,4,3};
    // vector<int> nums = {3,2,2,5,4};
    // vector<int> nums = {1,2,3,2};
    Solution S;
    cout << S.longestBalanced(nums) << endl;
    return 0;
}