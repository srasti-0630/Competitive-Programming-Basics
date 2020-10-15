/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.*/
class Solution {
public:
    int coinChange(vector<int>& c, int a) {
        if(c.size()==0){
            // if(a==0) return 1;
            return 0;
        }
        sort(c.begin(),c.end());
        int cn = 0;
        
        for(int i = c.size()-1;i>=0;i--){
            if(c[i]==a) return 1;
        }
        vector<int> dp(a+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<=a;i++){
            for(int j = 0;j<c.size();j++){
                if(i>=c[j]){
                    if(dp[i-c[j]]!=INT_MAX)
                    dp[i] = min(dp[i], 1+dp[i-c[j]]);
                }
            }
        }
        if(dp[a]==INT_MAX) return -1;
        return dp[a];
    }
};