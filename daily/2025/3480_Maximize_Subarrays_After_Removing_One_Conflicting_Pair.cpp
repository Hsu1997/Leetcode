#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> Min1(n+1, INT_MAX);
        vector<int> Min2(n+1, INT_MAX);
        for (auto& pair : conflictingPairs){
            int a = min(pair[0], pair[1]);
            int b = max(pair[0], pair[1]);
            if (b < Min1[a]){
                Min2[a] = Min1[a];
                Min1[a] = b;
            }
            else if (b < Min2[a]) Min2[a] = b;
        }
        long long res = 0;
        int smallest_range_index = n;
        int second_smallest = INT_MAX;
        vector<long long> remove_one_pair_conflict_starting_from_count(n+1, 0);
        for (int i = n; i > 0; i--){
            if (Min1[i] < Min1[smallest_range_index]){
                second_smallest = Min1[smallest_range_index];
                smallest_range_index = i;
            }
            else{
                second_smallest = min(second_smallest, Min1[i]);
            }
            res += min(n+1, Min1[smallest_range_index]) - i;
            remove_one_pair_conflict_starting_from_count[smallest_range_index] += min(n+1, min(second_smallest, Min2[smallest_range_index])) - min(n+1, Min1[smallest_range_index]);
        }
        return res + *max_element(remove_one_pair_conflict_starting_from_count.begin(), remove_one_pair_conflict_starting_from_count.end());
    }
};

int main(){
    // int n = 4;
    // vector<vector<int>> conflictingPairs = {{2,3},{1,4}};
    // int n = 5;
    // vector<vector<int>> conflictingPairs = {{1,2},{2,5},{3,5}};
    int n = 100000;
    vector<vector<int>> conflictingPairs = {{50000,50001},{99999,100000}};
    Solution S;
    cout << S.maxSubarrays(n, conflictingPairs) << endl;
    return 0;
}