// create a variable to store result
// create a map to store the elements and their key values
// iterate through i and j .
// find the difference between the elements present at i and j
// find if the difference is present in the map or not 
// make a count variable which can check if it reaches the end of the map searching for key .
// if key is not present assign count to 0 and if it is present access the key value by it->second
// modify the value at i 
// add it to the result and return it 

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int res=0;

        unordered_map<long,long> mp[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long diff = (long)nums[i]-nums[j];

                auto it = mp[j].find(diff);

                int count = it == end(mp[j]) ? 0: it->second;

                mp[i][diff] += count+1;

                res+=count;
            }
        }
        return res;
    }
};
