#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (int i : gifts) pq.push(i);
        for (int i = 0; i < k; i++){
            int curr = pq.top();
            pq.pop();
            pq.push(sqrt(curr));
        }
        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};

int main(){
    vector<int> gifts = {25,64,9,4,100};
    int k = 4;
    // vector<int> gifts = {1,1,1,1};
    // int k = 4;
    Solution S;
    cout << S.pickGifts(gifts, k) << endl;
    return 0;
}