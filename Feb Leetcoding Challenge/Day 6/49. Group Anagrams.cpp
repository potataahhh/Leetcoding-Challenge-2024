class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n =strs.size();
        vector<vector<string>>res;

        unordered_map<string,vector<string>> mp;

        for(int i=0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }

        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};

// Time Complexity - O(n*k*logk)    where n is the length of the word and k is the length of the longest word
// Space complexity - O(n*m)        because of unordered map
