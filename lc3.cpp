class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];

            // If character was already seen inside the current window
            if (last[c] >= left) {
                left = last[c] + 1;
            }

            last[c] = right;

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};