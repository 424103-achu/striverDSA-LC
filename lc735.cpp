class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int a : asteroids) {
            if (a > 0) {
                st.push(a);
                continue;
            }
            int destroyed = false;
            while (!st.empty() && st.top() > 0) {
                if (st.top() < -a) {
                    st.pop();
                } else if (st.top() == -a) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push(a);
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};