class Solution {
public:
// Recursion with Memoization
    int helper( string word1, string word2, int i, int j, vector<vector>& dp ){

        if(dp[i][j]>-1)
            return dp[i][j];
        
        else if(i==0)
            dp[i][j]=j;
        
        else if(j==0)
            dp[i][j]=i;
    
        else if(word2[i-1]==word1[j-1]){
            dp[i][j] = helper(word1,word2,i-1,j-1,dp);
        }
        
        else{
            dp[i][j] = 1+ min( helper(word1,word2,i-1,j-1,dp), 
            min( helper(word1,word2,i-1,j,dp), helper(word1,word2,i,j-1,dp)) );
        }
    
        return dp[i][j];
        
    }
    int minDistance(string word1, string word2) {
        
        int m=word2.size();
        int n=word1.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return helper(word1,word2,m,n,dp);    
    }

};