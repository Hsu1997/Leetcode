#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct worker{
        int quality;
        int wage;
        worker() : quality(0), wage(0) {}
        worker(int q, int w) : quality(q), wage(w) {}
    };

    static bool compare(worker a, worker b){
        return (double)a.wage / a.quality < (double)b.wage / b.quality; 
    }

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<worker> workers(n);
        for (int i = 0; i < n; i++) workers[i] = {worker(quality[i], wage[i])};
        sort(workers.begin(), workers.end(), compare);
        // for (worker i : workers) cout << i.quality << " " << i.wage << " " << (double)i.quality/i.wage << endl;
        int quality_acc = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0; i < k; i++){
            quality_acc += workers[i].quality;
            pq.push(workers[i].quality);
        }
        double ans = (double)workers[k-1].wage / workers[k-1].quality * quality_acc;
        // cout << (double)workers[k-1].wage / workers[k-1].quality << " * " << quality_acc << " = " << ans << endl;
        for (int i = k; i < n; i++){
            quality_acc -= pq.top();
            int temp = min(workers[i].quality, pq.top());
            pq.pop();
            ans = min(ans, (double)workers[i].wage / workers[i].quality * (quality_acc + temp));
            // cout << (double)workers[i].wage / workers[i].quality << " * " << (quality_acc + temp) << " = " << ans << endl;
            pq.push(min(temp, workers[i].quality));
            quality_acc += temp;
        }
        return ans;
    }
};

int main(){
    vector<int> quality = {10,20,5};
    vector<int> wage = {70,50,30};
    int k = 2;
    // vector<int> quality = {3,1,10,10,1};
    // vector<int> wage = {4,8,2,2,7};
    // int k = 3;
    // vector<int> quality = {4,4,4,5};
    // vector<int> wage = {13,12,13,12};
    // int k = 2;
    // vector<int> quality = {14,56,59,89,39,26,86,76,3,36};
    // vector<int> wage = {90,217,301,202,294,445,473,245,415,487};
    // int k = 2;
    Solution S;
    cout << S.mincostToHireWorkers(quality, wage, k) << endl;
    return 0;
}