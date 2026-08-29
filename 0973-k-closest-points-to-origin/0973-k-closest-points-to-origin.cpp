class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        vector<vector<int>> res;

        for(int i = 0; i < points.size();i++)
        {
            auto& point = points[i];
            int distance = point[0] * point[0] + point[1] * point[1];
            pq.push({distance,i});
            if(pq.size() > k) 
            {

                pq.pop();
            }
        }

        while(!pq.empty())
        {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};