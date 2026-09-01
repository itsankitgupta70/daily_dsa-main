class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        priority_queue<int> maxHeap;
        int time = 0;

        for (const auto& course : courses) {
            int duration = course[0];
            int deadline = course[1];

            time += duration;
            maxHeap.push(duration);

            if (time > deadline) {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};