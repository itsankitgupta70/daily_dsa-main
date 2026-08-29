class Solution {
public:
    using p = pair<long long, int>;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p> pq;

        for (int i = 0; i < points.size(); i++) {
            long long x = points[i][0];
            long long y = points[i][1];

            long long dis = x * x + y * y;

            pq.push({dis, i});

            if (pq.size() > k) {
                pq.pop();
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