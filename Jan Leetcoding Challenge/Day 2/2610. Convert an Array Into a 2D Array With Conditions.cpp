class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        // initialize row with 0
        int n =0;

        // map to find the frequency of each element
        map<int,int> mp;

        for(auto x: nums){
            // find the frequency of element x
            mp[x]++;
            
            // find the maximum frequency and that will be our number of rows
            n= max(n,mp[x]);
        }

        // 2d vector
        vector<vector<int>> ans(n);

        // set to find the unique element in the array
        vector<set<int>> s(n);

        for(auto x:nums){
            for(int i=0;i<n;i++){

                // check id the element is present in the set or not
                if(s[i].find(x)==s[i].end()){

                    //if not present then push_back in ans vector
                    ans[i].push_back(x);

                    // insert that element in set to have record of unique
                    s[i].insert(x);
                    break;
                }
            }
        }
        return ans;
    }
};
