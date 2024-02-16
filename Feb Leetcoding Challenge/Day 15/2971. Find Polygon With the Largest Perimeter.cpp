class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long res = -1;
        sort(nums.begin(),nums.end());

        long long sum = nums[0]+nums[1];

        for(int i=2;i<n;i++){
            if(nums[i]<sum)
                res= nums[i]+sum;
                sum+=nums[i];
            
        }
        return res;
    }
};
