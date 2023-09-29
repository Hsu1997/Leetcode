#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n == 1) return (gas[0] >= cost[0])? 0 : -1;
        // int max_cost = 0;
        int total_balance = 0;
        for (int i = 0; i < gas.size(); i++){
            gas[i] -= cost[i];
            total_balance += gas[i];
            // cout << gas[i] << " ";
        }
        // cout << endl;
        if (total_balance < 0) return -1;
        int start = 0;
        int end = 1;
        int acc = gas[start];
        while(end != start){
            if (acc >= 0) acc += gas[end], end = (end+1)%n;
            else start = (start-1+n)%n, acc += gas[start];
            // cout << "start = " << start << ", end = " << end << ", acc = " << acc << endl;
        }
        return start;
    }
};

int main(){
    // vector<int> gas = {1,2,3,4,5};
    // vector<int> cost = {3,4,5,1,2};
    // vector<int> gas = {2,3,4};
    // vector<int> cost = {3,4,3};
    vector<int> gas = {10,10,10,1,1,10};
    vector<int> cost = {1,1,1,15,15,1};
    Solution S;
    cout << S.canCompleteCircuit(gas, cost) << endl;
    return 0;
}