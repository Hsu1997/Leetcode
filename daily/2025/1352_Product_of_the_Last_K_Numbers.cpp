#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) prefix = {1};
        else prefix.push_back(num * prefix.back());
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) return 0;
        return prefix[n-1] / prefix[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main(){
    ProductOfNumbers productOfNumbers = ProductOfNumbers();
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]
    cout << productOfNumbers.getProduct(2) << " "; // return 20. The product of the last 2 numbers is 5 * 4 = 20
    cout << productOfNumbers.getProduct(3) << " "; // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    cout << productOfNumbers.getProduct(4) << " "; // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    productOfNumbers.add(8);        // [3,0,2,5,4,8]
    cout << productOfNumbers.getProduct(2) << endl; // return 32. The product of the last 2 numbers is 4 * 8 = 32 
    return 0;
}