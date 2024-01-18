class Solution {
public:

        int f(int ind,vector<int> &dp){
        if(ind==0) return 0;
        if(ind==1) return 1;
        if(ind==2) return 2;

        if(dp[ind]!=0){
            return dp[ind];
        }

        int left = f(ind-1,dp);
        int right = f(ind-2,dp);

        return dp[ind]=left+right;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        return f(n,dp);

    }
};
