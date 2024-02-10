class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return {};

        sort(nums.begin(),nums.end());

        vector<int> dp(n,0);
        vector<int> prev(n,-1);
        int maxi=0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;

                    if(dp[maxi]<dp[i]){
                        maxi=i;
                    }
                }
            }
        }

        vector<int> res;
        while(maxi>=0){
            res.push_back(nums[maxi]);
            maxi=prev[maxi];
        }
        return res;
    }
};
