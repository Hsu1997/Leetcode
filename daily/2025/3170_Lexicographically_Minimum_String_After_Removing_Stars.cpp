#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        auto cmp = [&](int i, int j){
            if (s[i] != s[j]) return s[i] > s[j];
            else return i < j;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        vector<bool> record(n, true);
        for (int i = 0; i < n; i++){
            if (s[i] == '*'){
                record[i] = false;
                if (!pq.empty()){
                    int temp = pq.top();
                    pq.pop();
                    record[temp] = false;
                }
            }
            else{
                pq.push(i);
            }
        }
        string ans;
        for (int i = 0; i < n; i++) if (record[i]) ans += s[i];
        return ans;
    }
};

int main(){
    string s = "aaba*";
    // string s = "abc";
    Solution S;
    cout << S.clearStars(s) << endl;
    return 0;
}