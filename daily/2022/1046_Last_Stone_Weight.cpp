#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        /*
        make_heap(stones.begin(), stones.end());
        while (stones.size() > 1) {
            int x = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int y = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            if (x == y) continue;

            stones.push_back(x - y);
            push_heap(stones.begin(), stones.end());
        }
        return stones.size() ? stones.front() : 0;
        */
        priority_queue<int> s;
        for (int i : stones) s.push(i);
        while(s.size() > 1){
            int i = s.top();
            s.pop();
            int j = s.top();
            s.pop();
            if (i == j) continue;
            else s.push(i - j);
        }
        return (s.empty())? 0:s.top();
    }
};

int main(){
    vector<int> stones = {2,7,4,1,8,1,1,1};
    Solution S;
    cout << S.lastStoneWeight(stones) << endl;
    return 0;
}