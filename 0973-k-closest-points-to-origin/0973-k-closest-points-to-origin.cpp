class Solution {
public:
    using p = pair<int, int>;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p, vector<p>> pq;
        for (int i = 0; i < k; i++) {
            int dis = sqrt((points[i][0] * points[i][0]) +
                           (points[i][1] * points[i][1]));
            pq.push({dis, i});
        }
        for (int i = k; i < points.size(); i++) {
            int dis = sqrt((points[i][0] * points[i][0]) +
                           (points[i][1] * points[i][1]));
            if (dis < pq.top().first) {
                pq.pop();
                pq.push({dis, i});
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};