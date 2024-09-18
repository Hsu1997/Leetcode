#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    static bool compare(const int& num1, const int& num2){
        if (num1 == 0) return false;
        if (num2 == 0) return true;
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        int n1 = s1.length();
        int n2 = s2.length();
        int lcm = n1 * n2 / gcd(n1, n2);
        int p1 = 0;
        int p2 = 0;
        for (int i = 0; i < lcm; i++){
            // s1 + s2;
            if (s1[p1] > s2[p2]) return true;
            // s2 + s1;
            else if (s1[p1] < s2[p2]) return false;
            else{
                p1 = (p1 + 1) % n1;
                p2 = (p2 + 1) % n2;
            }
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string ans;
        for (int i : nums) ans += to_string(i);
        if (ans[0] == '0') return "0";
        return ans;
    };
};

int main(){
    vector<int> nums = {10,2};
    // vector<int> nums = {3,30,34,5,9};
    // vector<int> nums = {0,0};
    // vector<int> nums = {111311, 1113};
    // vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Solution S;
    cout << S.largestNumber(nums) << endl;
    return 0;
}