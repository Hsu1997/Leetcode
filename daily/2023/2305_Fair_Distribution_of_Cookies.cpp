#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool valid_dis(vector<int> cookies, int c, int k){
        int ppl = 0;
        int taked = 0;
        int acc = 0;
        while(ppl < k && taked != cookies.size()){
            for (int i = 0; i < cookies.size(); i++){
                if (cookies[i] == -1) continue;
                else{
                    if (acc + cookies[i] <= c){
                        acc += cookies[i];
                        taked++;
                        cookies[i] = -1;
                    }
                }
            }
            ppl++;
            acc = 0;
        }
        // cout << " " << taked << " ";
        return taked == cookies.size();
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        sort(cookies.begin(), cookies.end(), greater<int>());
        int left = cookies[0];
        int right = 0;
        for (auto i : cookies) right += i;
        while(left < right){
            int mid = left + (right - left) / 2;
            // cout << "now checking " << mid << " : " << valid_dis(cookies, mid, k) << endl;
            if (valid_dis(cookies, mid, k)) right = mid;
            else left = mid+1; 
        }
        return right;
    }
};

int main(){
    vector<int> cookies = {8,15,10,20,8};
    int k = 2;
    // vector<int> cookies = {6,1,3,2,2,4,1,2};
    // int k = 3;
    Solution S;
    cout << S.distributeCookies(cookies, k) << endl;
    return 0;
}