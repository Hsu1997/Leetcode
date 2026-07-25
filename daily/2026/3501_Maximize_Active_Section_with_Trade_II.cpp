#include <iostream>
#include <vector>

using namespace std;

class SegmentTree{
public:
    SegmentTree(vector<int>& nums){
        while (p < nums.size()) p <<= 1;
        t.resize(p * 2);
        for (int i = 0; i < nums.size(); i++){
            t[p + i] = nums[i];
        }
        for (int i = p - 1; i > 0; i--){
            t[i] = max(t[i*2], t[i*2+1]);
        }
    }
    int query(int s, int e){
        s += p;
        e += p;
        int res = 0;
        while(s <= e){
            res = max({res, t[s], t[e]});
            s = (s + 1) / 2;
            e = (e - 1) / 2;
        }
        return res;
    }
private:
    int p = 1;
    vector<int> t;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int cntOne = 0;
        vector<int> contiguousZero;
        vector<int> pos;
        int accZero = 0;
        int accOne = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '0'){
                accZero++;
            }
            else{
                // s[i] == '1'
                cntOne++;
                if (accZero){
                    contiguousZero.push_back(accZero);
                    pos.push_back(i - accZero);
                    accZero = 0;
                }
            }
        }
        if (accZero){
            contiguousZero.push_back(accZero);
            pos.push_back(n - accZero);
        }
        if (contiguousZero.size() < 2) return vector(queries.size(), cntOne);
        vector<int> zerosum;
        for (int i = 0; i + 1 < contiguousZero.size(); i++) zerosum.push_back(contiguousZero[i] + contiguousZero[i+1]);
        SegmentTree S(zerosum);
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int l1 = upper_bound(pos.begin(), pos.end(), start) - pos.begin();
            if (s[start] == '0') l1--;
            int l2 = upper_bound(pos.begin(), pos.end(), end) - pos.begin() - 1;
            if (l1 >= l2 || (l1 == -1 && l2 < 1)){
                ans[i] = cntOne;
                continue;
            }
            int res = 0;
            int head = contiguousZero[l1];
            int tail = contiguousZero[l2];
            if (s[start] == '0'){
                // guarantee l1 > 0
                head -= (start - pos[l1]);
            }
            if (s[end] == '0'){
                tail = end - pos[l2] + 1;
            }
            if (l1 + 1 == l2) res = head + tail;
            else{
                res = head + contiguousZero[l1+1];
            }
            if (l2 - 1 != l1) res = max(res, contiguousZero[l2-1] + tail);
            l1++;
            l2--;
            if (l1 <= l2 - 1) res = max(res, S.query(l1, l2-1));
            ans[i] = res + cntOne;
        }
        return ans;
    }
};

int main(){
    string s = "01";
    vector<vector<int>> queries = {{0,1}};
    // string s = "0100";
    // vector<vector<int>> queries = {{0,3},{0,2},{1,3},{2,3}};
    // string s = "1000100";
    // vector<vector<int>> queries = {{1,5},{0,6},{0,4}};
    // string s = "01010";
    // vector<vector<int>> queries = {{0,3},{1,4},{1,3}};
    Solution S;
    vector<int> ans = S.maxActiveSectionsAfterTrade(s, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}