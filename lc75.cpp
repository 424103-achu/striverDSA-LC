class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {0, 0, 0};
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            a[nums[i]]++;
        }
        for (int i = 0, j = 0; i < n, j < 3;) {
            if (a[j] != 0) {
                nums[i] = j;
                a[j]--;
                i++;
            } else {
                j++;
            }
        }
    }
};
