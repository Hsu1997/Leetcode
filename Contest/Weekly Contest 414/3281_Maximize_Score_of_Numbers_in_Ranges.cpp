#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool is_vaild(vector<int>& start, int d, int dis){
        int temp = start[0];
        int n = start.size();
        for (int i = 1; i < n; i++){
            temp += dis;
            if (temp > start[i] + d) return false;
            if (temp > start[i]) continue;
            else temp = start[i];
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());
        int ans = 0;
        int left = 1;
        int right = (start[n-1] - start[0] + d) / (n - 1);
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (is_vaild(start, d, mid)){
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};

int main(){
    vector<int> start = {6,0,3};
    int d = 2;
    // vector<int> start = {2,6,13,13};
    // int d = 5;
    Solution S;
    cout << S.maxPossibleScore(start, d) << endl;
    return 0;
}