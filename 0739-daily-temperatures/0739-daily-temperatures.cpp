class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        vector<int> st;
        st.reserve(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && temperatures[st.back()] <= temperatures[i])
                st.pop_back();

            ans[i] = st.empty() ? 0 : st.back() - i;

            st.push_back(i);
        }
        return ans;
    }
};