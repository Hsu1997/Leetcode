#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool valid(vector<int>& position, int dis, int m){
        int c = 0;
        int pre = 0;
        for (int i = 1; i < position.size(); i++){
            if (position[i] - position[pre] >= dis){
                c++;
                pre = i;
                if (c == m) return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1;
        int right = (position.back() - position[0]) / (m - 1) + 1;
        while(left < right - 1){
            int mid = left + (right - left) / 2;
            if (valid(position, mid, m - 1)) left = mid;
            else right = mid;
        }
        return left;
    }
};

int main(){
    vector<int> position = {1,2,3,4,7};
    int m = 3;
    // vector<int> position = {5,4,3,2,1,1000000000};
    // int m = 2;
    Solution S;
    cout << S.maxDistance(position, m) << endl;
    return 0;
}