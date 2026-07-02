class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            if (start1 <= start2) {
                if (end1 >= start2) {
                    ans.push_back({max(start1, start2), min(end1, end2)});
                }
            } else {
                if (end2 >= start1) {
                    ans.push_back({max(start1, start2), min(end1, end2)});
                }
            }
            if (end1 <= end2) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};