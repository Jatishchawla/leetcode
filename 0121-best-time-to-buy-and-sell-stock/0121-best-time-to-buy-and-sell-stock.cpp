class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // find a sub pair or subsequence (first<second) with maximum difference
        int buy = 0;
        int sell = 1;
        int curr_profit = 0 ; // expected profit
        int msf = 0; // max profit so far
        for(int i = 1; i<prices.size(); i++ ){
            // sell=i; 
            curr_profit = prices[i]-prices[buy]; // if sold on curent i 
            msf = max(msf , curr_profit);
            buy = min(buy , i);
            sell= max(sell, i);
            if (curr_profit<0){  //or buy > prices[i]
                buy=i;
            }
            // else if(diff>msf){

            // }
        }
        return msf;
    }
};