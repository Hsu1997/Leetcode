#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    pair<long long, long long> dfs(string& s, int pos, int prev, int curr, bool isLimit, bool isLeading){
        if (pos == s.length()) return {1, 0};
        if (prev != -1 && curr != -1 && !isLimit && !isLeading && memoCnt[pos][prev][curr] != -1) return {memoCnt[pos][prev][curr], memoSum[pos][prev][curr]} ;
        long long cnt = 0;
        long long sum = 0;
        int up = isLimit? s[pos] - '0' : 9;
        for (int digit = 0; digit <= up; digit++){
            bool newIsLimit = isLimit && (digit == up);
            bool newIsLeading = isLeading && (digit == 0);
            int newPrev = curr;
            int newCurr = newIsLeading? -1 : digit;
            auto [subCnt, subSum] = dfs(s, pos + 1, newPrev, newCurr, newIsLimit, newIsLeading);
            cnt += subCnt;
            sum += subSum;
            if (prev != -1 && curr != -1 && !newIsLeading){
                if ((prev < curr && curr > digit) || (prev > curr && curr < digit)) sum += subCnt;
            }
        }
        if (prev != -1 && curr != -1 && !isLimit && !isLeading){
            memoCnt[pos][prev][curr] = cnt;
            memoSum[pos][prev][curr] = sum;
        }
        return {cnt, sum};
    }
    long long solve(long long limit){
        if (limit < 100) return 0;
        memset(memoCnt, -1, sizeof(memoCnt));
        memset(memoSum, -1, sizeof(memoSum));
        string s = to_string(limit);
        auto [_, ans] = dfs(s, 0, -1, -1, 1, 1);
        return ans;
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
private:
    long long memoCnt[16][10][10];
    long long memoSum[16][10][10];
};

int main(){
    int num1 = 120;
    int num2 = 130;
    // int num1 = 198;
    // int num2 = 202;
    // int num1 = 4848;
    // int num2 = 4848;
    Solution S;
    cout << S.totalWaviness(num1, num2) << endl;
    return 0;
}