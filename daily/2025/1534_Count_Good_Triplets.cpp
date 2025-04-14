#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int M = *max_element(arr.begin(), arr.end());
        // vector<vector<int>> acc(n, vector<int>(M+1, 0));
        // for (int j = arr[0]; j <= M; j++) acc[0][j] = 1;
        // for (int i = 1; i < n; i++){
            //     for (int j = 0; j <= M; j++){
                //         acc[i][j] = acc[i-1][j] + (j >= arr[i]);
                //     }
                // }
        vector<int> acc(M+1, 0);
        int ans = 0;
        for (int j = 1; j < n-1; j++){
            for (int i = arr[j-1]; i <= M; i++) acc[i]++;
            for (int k = j+1; k < n; k++){
                int second = arr[j];
                int third = arr[k];
                if (abs(second - third) > b) continue;
                // (second - a) ~ (second + a)
                // (third - c) ~ (third + c)
                int left = max({second - a, third - c, 0});
                int right = min({second + a, third + c, M});
                if (left > right) continue;
                if (left == 0) ans += acc[right];
                else ans += acc[right] - acc[left-1];
                // if (left == 0) ans += acc[j-1][right];
                // else ans += acc[j-1][right] - acc[j-1][left-1];
            }
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {3,0,1,1,9,7};
    int a = 7;
    int b = 2;
    int c = 3;
    // vector<int> arr = {1,1,2,2,3};
    // int a = 0;
    // int b = 0;
    // int c = 1;
    // vector<int> arr = {7,3,7,3,12,1,12,2,3};
    // int a = 5;
    // int b = 8;
    // int c = 1;
    Solution S;
    cout << S.countGoodTriplets(arr, a, b, c) << endl;
    return 0;
}