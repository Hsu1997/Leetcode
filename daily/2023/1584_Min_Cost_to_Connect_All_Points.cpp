#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class UnionSet {
public:
    vector<int> parent;
    UnionSet(int n){
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i){
        if (parent[i] == i) return i;
        else return parent[i] = find(parent[i]);
    }

    void combine(int i, int j){
        parent[find(i)] = find(j);
    }
};

int distance(vector<int>& a, vector<int>& b){return abs(a[0]-b[0]) + abs(a[1]-b[1]);}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_set<int> s;
        int ans = 0;
        // UnionSet S(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        s.insert(0);
        for (int i = 1; i < n; i++) pq.push({distance(points[0], points[i]), i});
        while(s.size() < n){
            auto [d, index] = pq.top();
            pq.pop();
            if (!s.count(index)){
                ans += d;
                s.insert(index);
                for (int i = 0; i < n; i++){
                    if (i != index && !s.count(i)) pq.push({distance(points[index], points[i]), i});
                }
            }
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    vector<vector<int>> points = {{3,12},{-2,5},{-4,1}};
    Solution S;
    cout << S.minCostConnectPoints(points) << endl;
    return 0;
}