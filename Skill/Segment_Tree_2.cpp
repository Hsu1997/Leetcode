// https://hackmd.io/@wiwiho/cp-note/%2F%40wiwiho%2FCPN-segment-tree
#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
public:
    int n;
    int height;
    int shift;
    vector<int> t;
    SegmentTree(vector<int>& v){
        n = v.size();
        int leaves = pow(2,ceil(log2(n)));
        int non_leaves = leaves - 1;
        // start with index 1
        shift = non_leaves + 1;
        int total = leaves + non_leaves;
        t = vector<int>(total + 1);
        for (int i = 0; i < n; i++) t[shift + i] = v[i];
        for (int i = non_leaves; i > 0; i--){
            int left = i * 2;
            int right = i * 2 + 1;
            t[i] = max(t[left], t[right]);
        }
    }
    void print_tree(){
        int c = 0;
        int temp = 0;
        for (int i : t){
            cout << i << " ";
            temp++;
            if (temp >= c){
                c += temp, temp = 0;
                cout << endl;
            }
        }
    }
    int query(int left, int right){
        left += shift;
        right += shift;
        int ans = INT_MIN;
        while(left <= right){
            if (left > 0 && left % 2 == 1) ans = max(ans, t[left++]);
            if (right > 0 && right % 2 == 0) ans = max(ans, t[right--]);
            left /= 2, right /= 2;
        }
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
        for (int power : worker) ans += T.query(0, min(M,power));
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
    // vector<int> difficulty = {66,1,28,73,53,35,45,60,100,44,59,94,27,88,7,18,83,18,72,63};
    // vector<int> profit = {66,20,84,81,56,40,37,82,53,45,43,96,67,27,12,54,98,19,47,77};
    // vector<int> worker = {61,33,68,38,63,45,1,10,53,23,66,70,14,51,94,18,28,78,100,16};
    vector<int> difficulty = {16,25,27};
    vector<int> profit = {14,21,52};
    vector<int> worker = {74,58,94};
    Solution S;
    cout << S.maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}