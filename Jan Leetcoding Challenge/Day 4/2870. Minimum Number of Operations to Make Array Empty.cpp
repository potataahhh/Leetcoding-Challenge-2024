class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;

        // check the frequency of all the element in the array
        for(int &num: nums){
            mp[num]++;
        }

        int res=0;

        // iterate through the map and find the frequency
        for(auto &it:mp){
            int freq=it.second;

        // ifthe frequency of the element is 1 we return -1 as per question
            if(freq==1){
                return -1;
            }

            // else we return the ceil of the frequency (convert the freq to double so that we can get decimal res)
            res+= ceil((double)freq/3);
        }
        return res;
    }
};
