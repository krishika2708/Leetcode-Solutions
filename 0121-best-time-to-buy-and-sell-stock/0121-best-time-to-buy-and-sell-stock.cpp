class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int maxprof=0;
        for(int i=0;i<n;i++){
                int cost=prices[i]-mini;
                maxprof=max(maxprof,cost);
                mini=min(prices[i],mini);

        }
        if(maxprof>0){
        return maxprof;
        }
        return 0;
    }
};