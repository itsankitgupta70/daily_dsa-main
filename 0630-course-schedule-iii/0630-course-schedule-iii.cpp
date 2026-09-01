class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        // Earliest deadlines first
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        priority_queue<int> pq;

        int total = 0;

        for (auto& course : courses) {
            int duration = course[0];
            int deadline = course[1];

            pq.push(duration);
            total += duration;

            if (total > deadline) {
                total -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};