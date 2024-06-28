#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> count(n);
        for (auto i : roads){
            count[i[0]]++;
            count[i[1]]++;
        }
        sort(count.begin(), count.end());
        long long ans = 0;
        long long k = 1;
        for (auto i : count) ans += i * k++;
        return ans;
    }
};

int main(){
    int n = 5;
    vector<vector<int>> roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    // int n = 5;
    // vector<vector<int>> roads = {{0,3},{2,4},{1,3}};
    Solution S;
    cout << S.maximumImportance(n, roads) << endl;
    return 0;
}