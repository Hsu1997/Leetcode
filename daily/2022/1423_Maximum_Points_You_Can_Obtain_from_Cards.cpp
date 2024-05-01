#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int M = 0;
        int point = 0;
        for (int i = 0; i < k; i++) point += cardPoints[i];
        if (k == n) return point;
        M = point;
        for (int i = k-1; i >= 0; i--){
            point = point - cardPoints[i] + cardPoints[n-k+i];
            // cout << i << " " << (n-k+i) << " " << point << endl;
            M = max(M, point);
        }
        return M;
    }
};

int main(){
    // vector<int> cardPoints = {1,2,3,4,5,6,1};
    // int k = 3;
    // vector<int> cardPoints = {2,2,2};
    // int k = 2;
    vector<int> cardPoints = {96,90,41,82,39,74,64,50,30};
    int k = 8;

    Solution S;
    cout << S.maxScore(cardPoints, k) << endl;
}