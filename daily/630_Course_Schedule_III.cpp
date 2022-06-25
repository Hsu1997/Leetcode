#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static bool mycompare(vector<int>& course1, vector<int>& course2){
        return (course1[1] != course2[1])? (course1[1] < course2[1]) : (course1[0] > course2[0]);
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), mycompare);
        // for (auto i : courses) cout << i[0] << "," << i[1] << " ";
        // cout << endl;

        int total_time = 0;
        priority_queue<int> pq;
        for (vector<int> course : courses){
            int duration = course[0];
            int lastday = course[1];

            // cout << "course " << duration << " : ";

            if (duration > lastday) continue;
            if (total_time + duration <= lastday) {
                total_time += duration;
                pq.push(duration);
            }
            else{
                if (duration >= pq.top()) continue;
                else{
                    total_time -= pq.top();
                    pq.pop();
                    total_time += duration;
                    pq.push(duration);
                }
            }
        }
        return pq.size();
    }
};

int main(){
    vector<vector<int>> courses = {{100,200},{200,1300},{1000,1250},{2000,3200}};
    Solution S;
    cout << S.scheduleCourse(courses) << endl;
}