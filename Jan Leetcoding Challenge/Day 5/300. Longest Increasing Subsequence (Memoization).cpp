class Solution {
public:

    int f(int ind,int prev,vector<int> &nums,vector<vector<int>> &dp){
        int n = nums.size();
        if(ind==n) return 0;

        // base condition for dp
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }

        // not take case
        int len = 0+f(ind+1,prev,nums,dp);

        // if we have 1 element in the array or the current element is greater than the prev , we take it
        if(prev==-1 || nums[ind]>nums[prev]){

            // take case
            len = max(len,1+f(ind+1,ind,nums,dp));
        }
        return dp[ind][prev+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return f(0,-1,nums,dp);
    }
};
