class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int wmaxsum=nums[0];
        // for (int i=0;i<nums.size();i++){
        //     int currentsum=nums[i];
        //     int maxsum=nums[i];
        //     for (int j=(i+1)%nums.size();j!=i;j=(j+1)%nums.size()){
        //         currentsum+=nums[j];
        //         if(currentsum>maxsum){
        //             maxsum=currentsum;
        //         }
        //     }
        //     if(maxsum>wmaxsum){
        //         wmaxsum=maxsum;
        //     }
        // }
        // return wmaxsum;
        int total=0;
        int currmax=0;
        int maxsum=nums[0];
        int currmin=0;
        int minsum=nums[0];
        for(int i:nums){
            currmax=max(i,currmax+i);
            maxsum=max(maxsum,currmax);
            currmin=min(i,currmin+i);
            minsum=min(minsum,currmin);
            total+=i;
        }
        if(maxsum<0){
            return maxsum;
        }
        return max(maxsum,total-minsum);
    }
};