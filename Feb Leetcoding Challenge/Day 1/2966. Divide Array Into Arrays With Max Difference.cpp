// create a resultant vector to store the result
// sort the array 
// iterate through the array starting from i=2, and with only 3 elements in the array , i.e i=i+3
//check for the value f k
// pushback in result vector
// return null
// return result

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(),nums.end());

        for(int i=2;i<=n;i=i+3){
            if(nums[i]-nums[i-2]<=k){
                res.push_back({nums[i-2],nums[i-1],nums[i]});
            }
            else{
                return {};
            }
        }
        return res;
    }
};
