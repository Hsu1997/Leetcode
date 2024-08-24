// 826. Most Profit Assigning Work
// Not Best Solution

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
public:
    vector<int> t;
    int height;
    SegmentTree(vector<int>& nums){
        int n = nums.size();
        height = ceil(log2(n))+1;
        // cout << "n = " << n << ", height = " << height << ", total = " << pow(2,(height))-1 << endl;
        t = vector<int>(4 * n, -1);
        for (int i = 0; i < n; i++) t[pow(2,height-1)+i] = nums[i];
        for (int i = pow(2,height-1)-1; i > 0; i--) t[i] = max(t[2*i], t[2*i+1]);
    }
    void print_tree(){
        int node = 0;
        int c = 0;
        for (auto i : t){
            c++;
            cout << i << " ";
            if (c >= node){
                cout << endl;
                node += c;
                c = 0;
            }
        }
    }
    int find_max(int i, int j){
        // cout << i << " to " << j << " : ";
        i += pow(2,height-1);
        j += pow(2,height-1);
        int ans = INT_MIN;
        while(i <= j){
            if (i % 2 == 1) ans = max(ans, t[i++]);
            if (j % 2 == 0) ans = max(ans, t[j--]);
            i /= 2;
            j /= 2;
        }
        // cout << ans << endl;
        return ans;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        int M = *max_element(difficulty.begin(), difficulty.end());
        vector<int> P(M+1, 0);
        for (int i = 0; i < difficulty.size(); i++) P[difficulty[i]] = max(P[difficulty[i]], profit[i]);
        // cout << "difficulty : " << endl;
        // for (auto i : P) cout << i << " ";
        // cout << endl << endl;
        SegmentTree T(P);
        for (int power : worker) ans += T.find_max(0, min(M, power));
        return ans;
    }
};

int main(){
    // vector<int> difficulty = {2,4,6,8,10};
    // vector<int> profit = {10,20,30,40,50};
    // vector<int> worker = {4,5,6,7};
    // vector<int> difficulty = {85,47,57};
    // vector<int> profit = {24,66,99};
    // vector<int> worker = {40,25,25};
    // vector<int> difficulty = {68,35,52,47,86};
    // vector<int> profit = {67,17,1,81,3};
    // vector<int> worker = {92,10,85,84,82};
    // vector<int> difficulty = {16,25,27};
    // vector<int> profit = {14,21,52};
    // vector<int> worker = {74,58,94};
    vector<int> difficulty = {66,1,28,73,53,35,45,60,100,44,59,94,27,88,7,18,83,18,72,63};
    vector<int> profit = {66,20,84,81,56,40,37,82,53,45,43,96,67,27,12,54,98,19,47,77};
    vector<int> worker = {61,33,68,38,63,45,1,10,53,23,66,70,14,51,94,18,28,78,100,16};
    Solution S;
    cout << S.maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}