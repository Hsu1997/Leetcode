#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class DSJ{
public:
    int n;
    vector<int> parents;
    DSJ(int _n){
        n = _n;
        parents = vector<int>(n);
        iota(parents.begin(), parents.end(), 0);
    }
    int find(int i){
        return parents[i] == i? i : parents[i] = find(parents[i]);
    }
    void combine(int i, int j){
        int x = find(i);
        int y = find(j);
        parents[y] = x;
    }
    unordered_map<int,vector<int>> allset(){
        unordered_map<int,vector<int>> m;
        for (int i = 0; i < n; i++) m[find(i)].push_back(i);
        return m;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int ans = 0;
        DSJ s(n);
        for (auto& a : allowedSwaps) s.combine(a[0], a[1]);
        unordered_map<int, vector<int>> m = s.allset();
        for (auto& [x, group] : m){
            unordered_map<int, int> cnt;
            for (int i : group) cnt[target[i]]++;
            for (int i : group){
                if (cnt[source[i]]) cnt[source[i]]--;
            }
            for (auto& [x, c] : cnt) ans += c;
        }
        return ans;
    }
};

int main(){
    vector<int> source = {1,2,3,4};
    vector<int> target = {2,1,4,5};
    vector<vector<int>> allowedSwaps = {{0,1},{2,3}};
    // vector<int> source = {1,2,3,4};
    // vector<int> target = {1,3,2,4};
    // vector<vector<int>> allowedSwaps = {};
    // vector<int> source = {5,1,2,4,3};
    // vector<int> target = {1,5,4,2,3};
    // vector<vector<int>> allowedSwaps = {{0,4},{4,2},{1,3},{1,4}};
    Solution S;
    cout << S.minimumHammingDistance(source, target, allowedSwaps) << endl;
    return 0;
}