#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int n;
    int k;
    bool odd;
    vector<int> power;
    vector<int> factorial;
    vector<string> palindrome;
    void find_palindrome(int index, int remainder, string temp){
        if (index == n / 2 + odd){
            if (remainder == 0) palindrome.push_back(temp);
            return;
        }
        for (int i = 0; i <= 9; i++){
            if (index == 0 && i == 0) continue;
            int add = 0;
            if (odd && index == n / 2){
                add = (i * power[index]) % k;
            }
            else{
                add = (i * (power[index] + power[n-1-index])) % k;
            }
            find_palindrome(index + 1, (remainder + add) % k, temp + to_string(i));
        }
    }
    long long countGoodIntegers(int n, int k) {
        this->n = n;
        this->k = k;
        odd = n % 2;
        power.resize(n+1);
        power[0] = 1 % k;
        factorial.resize(n+1);
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) factorial[i] = i * factorial[i-1];
        for (int i = 1; i < n; i++) power[i] = (power[i-1] * 10) % k;
        find_palindrome(0, 0, "");
        // for (auto i : palindrome) cout << i << " ";
        unordered_set<string> s;
        for (string i : palindrome){
            string head = i;
            reverse(i.begin(), i.end());
            if (odd) head.pop_back();
            head += i;
            sort(head.begin(), head.end());
            s.insert(head);
        }
        long long ans = 0;
        for (auto i : s){
            // cout << i << " ";
            long long temp = factorial[n];
            vector<int> count(10);
            for (auto j : i) count[j - '0']++;
            for (auto j : count) temp /= factorial[j];
            if (count[0]){
                long long sub = factorial[n-1];
                count[0]--;
                for (auto j : count) sub /= factorial[j];
                temp -= sub;
            }
            // cout << temp << endl;
            ans += temp;
        }
        return ans;
    }
};

int main(){
    // int n = 3;
    // int k = 5;
    // int n = 1;
    // int k = 4;
    int n = 5;
    int k = 6;
    Solution S;
    cout << S.countGoodIntegers(n, k) << endl;
    return 0;
}