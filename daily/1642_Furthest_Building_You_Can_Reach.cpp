#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int used_bricks = 0;

        for (int i = 0; i < heights.size() - 1; i++){
            if (heights[i] > heights[i+1]) continue;

            int needed = heights[i+1] - heights[i];
            if (pq.size() < ladders) pq.push(needed);
            else{
                if (ladders > 0 && needed > pq.top()){
                    used_bricks += pq.top();
                    pq.pop();
                    pq.push(needed);
                }
                else used_bricks += needed;
            }

            if (used_bricks > bricks) return i;
        }

        return heights.size() - 1;
    }
};

int main(){
    vector<int> heights = {4,2,7,6,9,14,12};
    int bricks = 5;
    int ladders = 1;
    // vector<int> heights = {4,12,2,7,3,18,20,3,19};
    // int bricks = 10;
    // int ladders = 2;
    // vector<int> heights = {14,3,19,3};
    // int bricks = 17;
    // int ladders = 0;
    Solution S;
    cout << S.furthestBuilding(heights, bricks, ladders) << endl;
}