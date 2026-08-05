class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minp = prices[0];
        int maxprofit = 0;
        int maxp=prices[0];
        int curr_profit=-1;
        for (int i = 1; i < n; i++) {
            if (prices[i] < minp) {
                minp = prices[i];
                maxp = prices[i];
            } else {
                maxp=max(maxp,prices[i]);
                curr_profit=maxp-minp;
            }
            if(maxprofit<curr_profit){
                maxprofit=curr_profit;
            }
        }
        return maxprofit;
    }
};
