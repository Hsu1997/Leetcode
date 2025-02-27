#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s;
        for (int i : arr) s.insert(i);
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int prev = arr[i];
                int curr = arr[j];
                int len = 2;
                // Can use DP to reduce redundant calculations
                while(s.find(prev + curr) != s.end()){
                    int temp = prev;
                    prev = curr;
                    curr += temp;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return (ans == 2)? 0 : ans;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    // vector<int> arr = {1,3,7,11,12,14,18};
    Solution S;
    cout << S.lenLongestFibSubseq(arr) << endl;
    return 0;
}