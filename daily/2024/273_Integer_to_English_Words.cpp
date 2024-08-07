#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> number = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> number_ten = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> number_teen = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    string helper(int num){
        string ans;
        if (num / 100) ans += number[num / 100] + " Hundred";
        num %= 100;
        if (num > 19){
            if (!ans.empty()) ans += " ";
            ans += number_ten[num / 10];
            if (num % 10) ans += " " + number[num % 10];
        }
        else if (num > 9){
            if (!ans.empty()) ans += " ";
            ans += number_teen[num % 10];
        }
        else if (num > 0){
            if (!ans.empty()) ans += " ";
            ans += number[num];
        }
        return ans;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<string> numeral = {"", " Thousand", " Million", " Billion"};
        string ans;
        int index = 0;
        while(num){
            int part = num % 1000;
            if (part > 0){
                string part_str = helper(part) + numeral[index];
                if (!ans.empty()) ans = part_str + " " + ans;
                else ans = part_str;
            }
            num /= 1000;
            index++;
        }
        return ans;
    }
};

int main(){
    int num = 123;
    // int num = 12345;
    // int num = 1234567;
    // int num = 1234567890;
    Solution S;
    cout << S.numberToWords(num) << endl;
    return 0;
}