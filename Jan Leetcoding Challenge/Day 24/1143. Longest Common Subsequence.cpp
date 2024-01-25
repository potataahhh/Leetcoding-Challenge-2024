class Solution {
public:

    int func(string &a,string &b,int i,int j,vector<vector<int>>& dp){
        if(i==a.size())
        return 0;
        if(j==b.size())
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int ans;
        if(a[i]==b[j]){
            ans = 1+func(a,b,i+1,j+1,dp);
        }
        else{
            ans= max(func(a,b,i+1,j,dp),func(a,b,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> >dp(text1.length(),vector<int>(text2.length(),-1));
        return func(text1,text2,0,0,dp);
    }
};
