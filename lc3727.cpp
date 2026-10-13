class Solution {
public:
    static long long maxAlternatingSum(vector<int>& nums) {
        const int n=nums.size(), h=n/2;
        for(auto& x : nums) x=abs(x);
        nth_element(nums.begin(), nums.begin()+h, nums.end());
        long long ans=0;
        for(int i=0; i<n; i++) 
            ans+=(i<h?-1:1)*(long long)nums[i]*nums[i];
        return ans;
    }
};