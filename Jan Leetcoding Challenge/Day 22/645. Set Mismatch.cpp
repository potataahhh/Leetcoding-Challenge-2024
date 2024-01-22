 // find the absolute value and make them negative.
// then check if it already marked negative or not .
// if it ismarked negative that means we found our duplicate value
// run a loop for missing value which will be i+1 for nums[i];


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int dup =-1;
        int missing =-1;

        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0){
                dup=abs(nums[i]);
            }
            else{
                nums[abs(nums[i])-1]*=(-1);
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                missing = i+1;
                break;
            }
        }
        return {dup,missing};
    }
};
