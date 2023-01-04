#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for (auto i : tasks) m[i]++;
        int ans = 0;
        for (auto i : m){
            if (i.second == 1) return -1;
            else{
                ans += (i.second/3) + (i.second %3 > 0);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    // vector<int> tasks = {2,3,3};
    Solution S;
    cout << S.minimumRounds(tasks) << endl;
    return 0;
}