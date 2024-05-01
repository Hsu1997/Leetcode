#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1 && target[0] != 1) return false;

        priority_queue<int> pq;
        unsigned int total = 0;
        for (auto i : target){
            pq.push(i);
            total += i;
        }

        while(pq.top() != 1){
            int temp = pq.top();
            pq.pop();
            total -= temp;
            if (temp <= total) return false;
            temp %= total;
            if (temp == 0) temp = total;
            total += temp;
            pq.push(temp);
        }
        return true;
    }
};

int main(){
    // vector<int> target = {9,3,5};
    // vector<int> target = {1,1,1,2};
    // vector<int> target = {8,5};
    // vector<int> target = {2,900000001};
    // vector<int> target = {1,1,999999999};
    vector<int> target = {2,900000002};
    Solution S;
    cout << S.isPossible(target) << endl;
    return 0;
}