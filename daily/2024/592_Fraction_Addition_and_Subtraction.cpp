#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        if (a < b) swap(a, b);
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    string fractionAddition(string expression) {
        int index = 0;
        int s = expression.length();
        int Numerator = 0;
        int Denominator = 1;
        while(index < s){
            int signal = 1;
            if (expression[index] == '-') signal = -1;
            if (!isdigit(expression[index])) index++;
            int temp_Numerator = 0;
            int temp_Denominator = 0;
            while(index < s && isdigit(expression[index])) temp_Numerator = temp_Numerator * 10 + (expression[index++] - '0');
            index++;
            while(index < s && isdigit(expression[index])) temp_Denominator = temp_Denominator * 10 + (expression[index++] - '0');
            // cout << "accu = " << ((Numerator >= 0)? '+':'-') << abs(Numerator) << " / " << Denominator << endl;
            // cout << "temp = " << ((signal == 1)? '+':'-') << temp_Numerator << " / " << temp_Denominator << endl;
            int common_factor = gcd(Denominator, temp_Denominator);
            // cout << "common factor = " << common_factor << endl;
            Numerator = Numerator * (temp_Denominator / common_factor) + temp_Numerator * (Denominator / common_factor) * signal;
            // cout << "Numerator = " << Numerator << endl;
            if (Numerator == 0) Denominator = 1;
            else Denominator *= (temp_Denominator / common_factor);
            // cout << "Denominator = " << Denominator << endl;
            common_factor = gcd(abs(Numerator), Denominator);
            // cout << "common factor = " << common_factor << endl;
            Numerator /= common_factor;
            Denominator /= common_factor;
        }
        string ans;
        ans = to_string(Numerator) + '/' + to_string(Denominator);
        return ans;
    }
};

int main(){
    string expression = "-1/2+1/2";
    // string expression = "-1/2+1/2+1/3";
    // string expression = "1/3-1/2";
    // string expression = "-4/7-3/4+2/3";
    Solution S;
    cout << S.fractionAddition(expression) << endl;
    return 0;
}