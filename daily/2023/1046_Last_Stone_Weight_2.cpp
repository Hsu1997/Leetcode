#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que;
        for (auto i : stones) que.push(i);
        while(que.size() > 1){
            int a = que.top();
            que.pop();
            int b = que.top();
            que.pop();
            if (a == b) continue;
            que.push(abs(a-b));
        }
        return (que.size() == 0)? 0 : que.top();
    }
};

int main(){
    // vector<int> stones = {2,7,4,1,8,1};
    vector<int> stones = {1};
    Solution S;
    cout << S.lastStoneWeight(stones) << endl;
    return 0;
}