#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int time = 0;
        for (auto i : customers){
            time = max(i[0], time) + i[1];
            ans += time - i[0];
        }
        return ans / customers.size();
    }
};

int main(){
    // vector<vector<int>> customers = {{1,2},{2,5},{4,3}};
    vector<vector<int>> customers = {{5,2},{5,4},{10,3},{20,1}};
    Solution S;
    cout << S.averageWaitingTime(customers) << endl;
    return 0;
}