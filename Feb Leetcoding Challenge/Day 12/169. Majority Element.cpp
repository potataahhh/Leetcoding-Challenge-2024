class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int curr = 0;
        for(int i=0;i<n;i++){
            if(count==0){
                curr=nums[i];
                count=1;
            }
            else if(curr==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return curr;
    }
};
