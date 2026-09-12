class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long  sum=0;
        int n=happiness.size();
        int count=0;
        for(int i=0;i<k;i++){
            sum+=max(happiness[n-1-i]-count,0);
            count++;
        }
        return sum;
    }
};