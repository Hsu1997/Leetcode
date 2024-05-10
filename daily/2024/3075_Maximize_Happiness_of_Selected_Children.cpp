#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        int round = 0;
        for (int i : happiness) pq.push(i);
        while(round < k && !pq.empty()){
            ans += max(pq.top() - round, 0);
            pq.pop(), round++;
        }
        return ans;
    }
};

int main(){
    vector<int> happiness = {1,2,3};
    int k = 2;
    // vector<int> happiness = {1,1,1,1};
    // int k = 2;
    // vector<int> happiness = {2,3,4,5};
    // int k = 1;
    Solution S;
    cout << S.maximumHappinessSum(happiness, k) << endl;
    return 0;
}