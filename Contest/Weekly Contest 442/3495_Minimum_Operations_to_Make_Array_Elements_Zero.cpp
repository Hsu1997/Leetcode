#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& query : queries){
            ans += operation_count(query);
        }
        return ans;
    }
    long long operation_count(vector<int>& query){
        int start = query[0];
        int end = query[1];
        long long ans = sun_problem(end) - sun_problem(start - 1);
        ans = (ans + 1) / 2;
        return ans;
    }
    long long sun_problem(long long end){
        if (end < 4) return end;
        long long ans = 3;
        long long temp = 4;
        long long curr_ans = 2;
        while(temp <= end){
            temp *= 4;
            ans += curr_ans * (min(end + 1, temp) - temp/4);
            curr_ans++;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> queries = {{1,2},{2,4}};
    // vector<vector<int>> queries = {{2,6}};
    Solution S;
    cout << S.minOperations(queries) << endl;
    return 0;
}