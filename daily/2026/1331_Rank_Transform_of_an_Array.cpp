#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        vector<int> res = arr;
        sort(res.begin(), res.end());
        unordered_map<int,int> rank;
        rank[res[0]] = 1;
        for (int i = 1; i < res.size(); i++){
            rank[res[i]] = rank[res[i-1]] + (res[i] > res[i-1]);
        }
        vector<int> ans;
        ans.reserve(arr.size());
        for (int i : arr) ans.push_back(rank[i]);
        return ans;
    }
};

int main(){
    vector<int> arr = {40,10,20,30};
    // vector<int> arr = {100,100,100};
    // vector<int> arr = {37,12,28,9,100,56,80,5,12};
    Solution S;
    vector<int> ans = S.arrayRankTransform(arr);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}