class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int tot = 1 << k;
        if (n - k + 1 < tot) return false;

        // Use a boolean array/vector as a hash set for O(1) integer lookups
        std::vector<bool> visited(tot, false);
        int current_hash = 0;
        int mask = tot - 1; // Used to keep only the last k bits
        int unique_count = 0;

        for (int i = 0; i < n; i++) {
            // Shift left and add the new bit
            current_hash = ((current_hash << 1) & mask) | (s[i] - '0');
            
            // Once the window reaches size k, start tracking
            if (i >= k - 1) {
                if (!visited[current_hash]) {
                    visited[current_hash] = true;
                    unique_count++;
                    if (unique_count == tot) return true;
                }
            }
        }

        return false;
    }
};
