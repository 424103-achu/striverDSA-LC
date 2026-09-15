#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;
int spf[MAXN + 1];

// Precompute Smallest Prime Factor (SPF) for all numbers up to 10^6
auto init = []() {
    for (int i = 1; i <= MAXN; i++) spf[i] = i;
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    return true;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                // Reduce nums[i] to its smallest prime factor
                nums[i] = spf[nums[i]];
                ops++;

                // If it's still strictly greater, it's impossible
                if (nums[i] > nums[i + 1]) {
                    return -1;
                }
            }
        }

        return ops;
    }
};