class Solution {
public:

    int f(int n,vector<int> &dp){

        int res =n;
        if(n<=0) return 0;
        if(dp[n]!=-1){
            return dp[n];
        }

        for(int i=1;i*i<=n;i++){
            int sq=i*i;

            res = min(res,1+f(n-sq,dp));
        }
        return dp[n] = res;
    }

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};
