#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<int> remainder(n);
        remainder[0] = 1;
        for (int i = 1; i < n; i++) remainder[i] = remainder[i-1] * 10 % k;
        vector<int> factorial(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) factorial[i] = factorial[i-1] * i;
        vector<string> palindrome;
        dfs(0, 0, "", n, k, palindrome, remainder);
        // for (auto s : palindrome) cout << s << " ";
        unordered_set<string> s;
        for (string p : palindrome){
            string temp = p;
            reverse(temp.begin(), temp.end());
            if (n % 2 == 1) p.pop_back();
            p += temp;
            sort(p.begin(), p.end());
            s.insert(p);
        }
        // for (auto t : s) cout << t << endl;
        long long ans = 0;
        for (string p : s){
            vector<int> count(10);
            for (char c : p) count[c - '0']++;
            long long f = factorial[n];
            for (int i : count) f /= factorial[i];
            if (count[0]){
                long long sub = factorial[n-1];
                count[0]--;
                for (int i : count) sub /= factorial[i];
                f -= sub;
            }
            ans += f;
        }
        return ans;
    }
    void dfs(int index, int r, string temp, int n, int k, vector<string>& palindrome, vector<int>& remainder){
        if (index == (n + 1) / 2){
            if (r == 0) palindrome.push_back(temp);
            return;
        }
        for (int i = 0; i < 10; i++){
            if (index == 0 && i == 0) continue;
            int add;
            if (n % 2 == 1 && index == n / 2){
                add = (i * remainder[index]) % k;
            }
            else{
                add = (i * (remainder[index] + remainder[n - 1 - index])) % k;
            }
            dfs(index+1, (r + add) % k, temp + to_string(i), n, k, palindrome, remainder);
        }
    }
};

int main(){
    int n = 3;
    int k = 5;
    // int n = 1;
    // int k = 4;
    // int n = 5;
    // int k = 6;
    Solution S;
    cout << S.countGoodIntegers(n, k) << endl;
    return 0;
}