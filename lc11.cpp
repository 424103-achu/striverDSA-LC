class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int tot_max = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            tot_max=max(tot_max,area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return tot_max;
    }
};