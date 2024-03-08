class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> res(101);
        int maxi=0;

        for(int &nums:nums){
            res[nums]++;
            maxi=max(maxi,res[nums]);
        }
        return std::count(begin(res),end(res),maxi)*maxi;
    }
};
