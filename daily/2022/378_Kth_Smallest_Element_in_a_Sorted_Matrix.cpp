#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class mycompare {
public:
    bool operator()(vector<int> a, vector<int> b){
        return a[0] <= b[0];
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        for (auto i : matrix){
            for (auto j : i){
                pq.push(j);
                if (pq.size() > k) pq.pop();
            }
        }

        return pq.top();
    }
};

int main(){
    // vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    // int k = 8;
    vector<vector<int>> matrix = {{-5}};
    int k = 1;
    Solution S;
    cout << S.kthSmallest(matrix, k) << endl;
    return 0;
}