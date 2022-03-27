#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// bool compare(pair<int, int> &a, pair<int, int> &b){
//     if (a.first == b.first) return (a.second < b.second)? true:false;
//     return a.first < b.first;
// }

struct pair_compare{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if (a.first == b.first) return (a.second < b.second)? true:false;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, pair_compare> max_heap;
        vector<int> ans;
        for (int i = 0; i < mat.size(); i++){
            int head = 0;
            int tail = mat[i].size() - 1;
            while(head <= tail){
                int mid = head + (tail - head) / 2;
                // find the first 0 in the vector, the position of 1st 0 is the number of 1
                if (mat[i][mid] == 0) tail = mid - 1;
                else head = mid + 1;
            }
            max_heap.push(make_pair(head, i));
            if (max_heap.size() > k) max_heap.pop();
        }
        while(max_heap.size()){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    vector<vector<int>> mat = {{1,1,0,0,0},
                               {1,1,1,1,0},
                               {1,0,0,0,0},
                               {1,1,0,0,0},
                               {1,1,1,1,1}};
    int k = 3;
    Solution S;
    vector<int> ans = S.kWeakestRows(mat, k);
    for (auto i : ans) cout << i << " ";
    cout << '\n';
    return 0;
}