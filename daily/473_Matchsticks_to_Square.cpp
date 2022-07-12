#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int side;

    bool subproblem(vector<int>& matchsticks, int i, int remain, int done){
        if (done == 3) return true;

        for (; i < matchsticks.size(); i++){
            int now_length = matchsticks[i];
            if (now_length > remain) continue;
            bool temp = false;
            matchsticks[i] = side + 1;
            if (now_length == remain) temp = subproblem(matchsticks, 1, side, done + 1);
            else temp = subproblem(matchsticks, i+1, remain - now_length, done);
            if (temp) return true;
            matchsticks[i] = now_length;
            while(i < matchsticks.size() && matchsticks[i+1] == now_length) i++;
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater());
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        side = total / 4;
        if (total % 4 || matchsticks[0] > side) return false;
        
        return subproblem(matchsticks, 0, side, 0);
    }
};

int main(){
    // vector<int> matchsticks = {1,1,2,2,2};
    vector<int> matchsticks = {5,5,5,5,4,4,4,4,3,3,3,3};
    Solution S;
    cout << S.makesquare(matchsticks) << endl;
    return 0;
}