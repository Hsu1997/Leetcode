#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

class Solution {
public:
    ll palindrome(string s, bool odd){
        ll ans = stol(s);
        for (int i = s.length() - 1 - odd; i >= 0; i--){
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
       
    string nearestPalindromic(string n) {
        int s = n.length();
        bool odd = s % 2;
        vector<ll> v;
        string half = n.substr(0, (s + 1) / 2);
        v.push_back(palindrome(half, odd));
        v.push_back(palindrome(to_string(stol(half) + 1), odd));
        v.push_back(palindrome(to_string(stol(half) - 1), odd));
        v.push_back(pow(1LL*10, s - 1) - 1);
        v.push_back(pow(1LL*10, s) + 1);
        ll diff = LLONG_MAX;
        string ans;
        for (auto l : v){
            if (l == stol(n)) continue;
            if (abs(l - stol(n)) < diff) diff = abs(l - stol(n)), ans = to_string(l);
            if (abs(l - stol(n)) == diff && l < stol(ans)) ans = to_string(l);
        }
        return ans;
    }
};

// class Solution {
// public:
//     string plus_one(string n){
//         int i = n.length() - 1;
//         int temp = 1;
//         while(i >= 0 && temp != 0){
//             temp = n[i] - '0' + temp;
//             n[i] = temp % 10 + '0';
//             temp /= 10;
//             i--;
//         }
//         if (temp > 0) n = "1" + n;
//         // cout << n << endl;
//         return n;
//     }
//     string minus_one(string n){
//         int i = n.length() - 1;
//         int temp = -1;
//         while(i >= 0 && temp != 0){
//             temp = n[i] - '0' + temp;
//             if (temp >= 0) n[i] = temp + '0', temp = 0;
//             else{
//                 n[i] = '9', temp = -1;
//             }
//             i--;
//         }
//         if (n.length() > 1 && n[0] == '0') n = n.substr(1);
//         // cout << n << endl;
//         return n;
//     }
//     string find_bigger(string n){
//         int s = n.length();
//         int left = 0;
//         int right = s - 1;
//         while(left < right){
//             if (n[left] == n[right]) left++, right--;
//             else{
//                 if (n[left] > n[right]) n[right] = n[left];
//                 else{
//                     n[right] = n[left];
//                     int index = right - 1;
//                     int temp = n[index] - '0' + 1;
//                     while(index >= 0 && temp == 10){
//                         n[index] = '0';
//                         index--;
//                         temp = n[index] - '0' + 1;
//                     }
//                     if (temp < 10) n[index] = '0' + temp;
//                     else n = "1" + n;
//                     return find_bigger(n);
//                 }
//             }
//         }
//         return n;
//     }
//     string find_smaller(string n){
//         if (n.length() == 1) return n;
//         int s = n.length();
//         int left = 0;
//         int right = s - 1;
//         while(left < right){
//             if (n[left] == n[right]) left++, right--;
//             else{
//                 if (n[left] < n[right]) n[right] = n[left];
//                 else{
//                     if (left + 1 == right && n[left] == '1' && n[right] == '0') n[left] = '0', n[right] = '9';
//                     else{
//                         n[right] = n[left];
//                         int index = right - 1;
//                         int temp = n[index] - '0' - 1;
//                         while(index >= 0 && temp < 0){
//                             n[index--] = '9';
//                             temp = n[index] - '0' - 1;
//                         }
//                         if (temp < 0) return "error";
//                         else n[index] = temp + '0';
//                     }
//                     for (int i = 0; i < n.length(); i++) if (n[i] != '0') return find_smaller(n.substr(i));
//                     return find_smaller(n);
//                 }
//             }
//         }
//         return n;
//     }
//     string find_diff(string n1, string n2){
//         string t(n1.length() - n2.length(), '0');
//         n2 = t + n2;
//         int temp = 0;
//         string s;
//         for (int i = n1.length() - 1; i >= 0; i--){
//             temp += (n1[i] - '0') - (n2[i] - '0');
//             if (temp < 0){
//                 temp += 10;
//                 s += temp + '0';
//                 temp = -1;    
//             }
//             else{
//                 s += temp + '0';
//                 temp = 0;
//             }
//         }
//         reverse(s.begin(), s.end());
//         for (int i = 0; i < s.length(); i++){
//             if (s[i] != '0') return s.substr(i);
//         }
//         return "0";
//     }
//     string nearestPalindromic(string n) {
//         // cout << plus_one(n) << endl;
//         // cout << minus_one(n) << endl;
//         string bigger = find_bigger(plus_one(n));
//         string smaller = find_smaller(minus_one(n));
//         string bigger_diff = find_diff(bigger, n);
//         string smaller_diff = find_diff(n, smaller);
//         cout << "Big : " << bigger << " " << bigger_diff << endl;
//         cout << "Small : " << smaller << " " << smaller_diff << endl;
//         if (bigger_diff == smaller_diff) return smaller;
//         if (bigger_diff.length() == smaller_diff.length()){
//             return (bigger_diff < smaller_diff)? bigger : smaller;
//         }
//         return (bigger_diff.length() < smaller_diff.length())? bigger : smaller;
//     }
// };

int main(){
    string n = "123";
    // string n = "1";
    // string n = "989";
    // string n = "10";
    // string n = "11";
    // string n = "10001";
    Solution S;
    cout << S.nearestPalindromic(n) << endl;
    return 0;
}