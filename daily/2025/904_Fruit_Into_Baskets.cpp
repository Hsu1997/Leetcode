#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int max_type = 2;
        unordered_map<int,int> curr;
        int i = 0;
        int n = fruits.size();
        for (int j = 0; j < n; j++){
            curr[fruits[j]] ++;
            while (curr.size() > max_type && i <= j){
                curr[fruits[i]]--;
                if (curr[fruits[i]] == 0) curr.erase(fruits[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main(){
    vector<int> fruits = {1,2,1};
    // vector<int> fruits = {0,1,2,2};
    // vector<int> fruits = {1,2,3,2,2};
    Solution S;
    cout << S.totalFruit(fruits) << endl;
    return 0;
}