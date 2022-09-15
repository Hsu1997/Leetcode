#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans = 0;
        int n = properties.size();
        sort(properties.begin(), properties.end());

        // for (auto i : properties){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        int M = 0;
        int temp_M = properties[n-1][1];
        for (int i = n-2; i >= 0; i--){
            if (properties[i][0] == properties[i+1][0]) temp_M = max(temp_M, properties[i][1]);
            else M = max(M, temp_M), temp_M = properties[i][1];
            
            if (properties[i][1] < M) ans++;
        }

        return ans;
    }
};

int main(){
    // vector<vector<int>> properties = {{5,5},{6,3},{3,6}};
    // vector<vector<int>> properties = {{2,2},{3,3}};
    // vector<vector<int>> properties = {{1,5},{10,4},{4,3}};
    vector<vector<int>> properties = {{4,5},{4,4},{4,3},{3,6}};
    Solution S;
    cout << S.numberOfWeakCharacters(properties) << endl;
    return 0;
}