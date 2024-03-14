class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         int zero = 0;
        int sum = 0;
        int count = 0;
        
        int i = 0, j = 0;
        
        while(j < nums.size()) {
            sum += nums[j];
            
            while (i < j && (nums[i] == 0 || sum > goal)) {
                if (nums[i] == 1) {
                    zero = 0;
                } else {
                    zero += 1;
                }
                
                sum -= nums[i];
                i++;
            }
            
            if (sum == goal) {
                count += 1 + zero;
            }
            j++;
        }
        
        return count;
    }
};
