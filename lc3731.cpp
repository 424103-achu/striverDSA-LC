class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minn=101;
        int maxn=-1;
        vector<int>ans;
        bool present[101]={false};
        for (int i=0;i<nums.size();i++){
            minn=min(nums[i],minn);
            maxn=max(maxn,nums[i]);
           present[nums[i]]=true;
        }
        for (int i=minn+1;i<maxn;i++){
            if(!present[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
