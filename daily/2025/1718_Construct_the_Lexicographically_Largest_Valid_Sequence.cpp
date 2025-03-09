#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, -1);
        vector<bool> used(n + 1, false);
        track(0, n, result, used);
        return result;
    }
    bool track(int pos, int n, vector<int>& result, vector<bool>& used){
        if (pos == result.size()) return true;
        if (result[pos] != -1) return track(pos+1, n, result, used);
        for (int num = n; num > 1; num--){
            if (used[num] || result[pos] != -1 || pos + num >= 2 * n - 1 || result[pos + num] != -1) continue;
            result[pos] = num;
            result[pos + num] = num;
            used[num] = true;
            if (track(pos+1, n, result, used)) return true;
            result[pos] = -1;
            result[pos + num] = -1;
            used[num] = false;
        }
        if (!used[1] && result[pos] == -1){
                used[1] = true;
                result[pos] = 1;
                if (track(pos+1, n, result, used)) return true;
                used[1] = false;
                result[pos] = -1;
        }
        return false;
    }
};

int main(){
    int n = 3;
    // int n = 5;
    // int n = 9;
    // int n = 20;
    Solution S;
    vector<int> ans = S.constructDistancedSequence(n);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}