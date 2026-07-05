class Solution {
public:
    string removeDuplicates(string s, int k) {

        string ans;
        vector<int> cnt;

        for (char c : s) {

            ans.push_back(c);

            if (ans.size() == 1 || ans.back() != ans[ans.size() - 2])
                cnt.push_back(1);
            else
                cnt.push_back(cnt.back() + 1);

            if (cnt.back() == k) {
                for (int i = 0; i < k; i++) {
                    ans.pop_back();
                    cnt.pop_back();
                }
            }
        }

        return ans;
    }
};