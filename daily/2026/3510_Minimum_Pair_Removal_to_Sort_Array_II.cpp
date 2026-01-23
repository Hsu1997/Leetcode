#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& _nums) {
        int n = _nums.size();
        vector<long long> nums(n);
        for (int i = 0; i < n; i++) nums[i] = 1LL * _nums[i];
        vector<int> prev(n);
        vector<int> next(n);
        for (int i = 0; i < n; i++){
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        next[n-1] = -1;
        vector<int> version(n, 0);
        int op = 0;
        int bad = 0;
        for (int i = 0; i < n - 1; i++) if (nums[i] > nums[i+1]) bad++;
        struct node{
            int i;
            long long sum;
            int ver;
            node(int _i, long long _s, int _v) : i(_i), sum(_s), ver(_v) {};
            bool operator>(const node& other) const{
                if (sum == other.sum) return i > other.i;
                else return sum > other.sum;
            }
        };
        priority_queue<node, vector<node>, greater<>> pq;
        for (int i = 0; i < n - 1; i++) pq.push(node(i, 1LL * nums[i] + nums[next[i]], 0));
        while(bad){
            int i, j, p, q;
            while(!pq.empty()){
                node curr = pq.top();
                pq.pop();
                i = curr.i;
                j = next[i];
                if (i == -1 || j == -1) continue;
                if (curr.ver != version[i]) continue;
                p = prev[i];
                q = next[j];
                break;
            }
            // p (i j) q
            if (nums[i] > nums[j]) bad--;
            if (p != -1 && nums[p] > nums[i]) bad--;
            if (q != -1 && nums[j] > nums[q]) bad--;
            nums[i] += nums[j];
            version[i]++;
            version[j]++;
            next[i] = q;
            if (q != -1) prev[q] = i;

            if (p != -1 && nums[p] > nums[i]) bad++;
            if (q != -1 && nums[i] > nums[q]) bad++;
            op++;
            if (p != -1){
                version[p]++;
                pq.push(node(p, 1LL * nums[p] + nums[i], version[p]));
            }
            if (q != -1){
                pq.push(node(i, 1LL * nums[i] + nums[q], version[i]));
            }
        }
        return op;
    }
};

int main(){
    vector<int> nums = {5,2,3,1};
    // vector<int> nums = {1,2,2};
    Solution S;
    cout << S.minimumPairRemoval(nums) << endl;
    return 0;
}