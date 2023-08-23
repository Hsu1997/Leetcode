#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        int n = s.length();
        int threshold = (n+1)/2;
        vector<int> count(26,0);
        for (char i : s) count[i-'a']++;
        priority_queue<pair<int,char>> pq;
        for (int i = 0; i < 26; i++){
            if (count[i] == 0) continue;
            if (count[i] > threshold) return "";
            pq.push({count[i], 'a'+i});
            // cout << (char)('a'+i) << " : " << count[i] << endl;
        }
        while(pq.size() > 1){
            auto [freq1, char1] = pq.top(); pq.pop();
            auto [freq2, char2] = pq.top(); pq.pop();
            ans += char1;
            ans += char2;
            if (--freq1 > 0) pq.push({freq1, char1});
            if (--freq2 > 0) pq.push({freq2, char2});
        }
        if (!pq.empty()) ans += pq.top().second;
        return ans;
    }
};

int main(){
    // string s = "aab";
    string s = "aaab";
    Solution S;
    cout << S.reorganizeString(s) << endl;
    return 0;
}