#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() < 2) return ratings.size();

        vector<int> c(ratings.size(), 1);

        int up = 0;
        int continues = 1;

        for (int i = 1; i < ratings.size(); i++){
            if (up == 0){
                if (ratings[i-1] < ratings[i]) up = 1, continues = 1;
                else if (ratings[i-1] > ratings[i]) up = -1, continues = 1;
                else up = 0, continues = 1;
            }
            if ((up == 1 && ratings[i-1] < ratings[i]) || (up == -1 && ratings[i-1] > ratings[i])) continues++;
            else{
                for (int j = i-1; j >= i-continues; j--){
                    if (up == 1) c[j] = max(c[j],continues+(j-i+1));
                    else c[j] = max(c[j],i-j);
                }

                if (ratings[i-1] == ratings[i]) up = 0;
                else up = (ratings[i-1] < ratings[i])? 1:-1;
                continues = 2;
            }
            // cout << "continues = " << continues << " : ";
            // for (auto i : c) cout << i << " ";
            // cout << endl;
        }

        // cout << "deal with end, up = " << up << endl;
        if (up == 1){
            int temp = 1;
            while(ratings.size()-continues < ratings.size() && continues >= 0){
                c[ratings.size()-continues] = max(c[ratings.size()-continues], temp), continues--, temp++;
            }
        }
        else if (up == -1){
            while(ratings.size()-continues < ratings.size() && continues >= 0){
                c[ratings.size()-continues] = max(c[ratings.size()-continues], continues), continues--;
            }
        }

        // for (auto i : c) cout << i << " ";
        // cout << endl;

        return accumulate(c.begin(), c.end(), 0);
    }
};

int main(){
    vector<int> ratings = {1,2,3,4,5,6,4,3,4,4,4,4,4};
    Solution S;
    cout << S.candy(ratings) << endl;
    return 0;
}