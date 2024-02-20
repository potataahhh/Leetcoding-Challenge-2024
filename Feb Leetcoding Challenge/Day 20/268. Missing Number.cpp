class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;

        for(int i=0;i<n;i++){
            sum-=nums[i];
        }
        return sum;
    }
};

// XOR GATES

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;

        for(int i=0;i<n;i++){
            res^=i;
            res^=nums[i];
        }
        return res;
    }
};
