#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        // for (auto i : satisfaction) cout << i << " ";
        int total = 0;
        int acc = 0;
        int s = 0;
        while(s < satisfaction.size() && acc + satisfaction[s] > 0){
            acc += satisfaction[s];
            total += acc;
            s++;
        }
        return total;
    }
};

int main(){
    vector<int> satisfaction = {-1,-8,0,5,-9};
    // vector<int> satisfaction = {4,3,2};
    // vector<int> satisfaction = {-1,-4,-5};
    Solution S;
    cout << S.maxSatisfaction(satisfaction) << endl;
    return 0;
}