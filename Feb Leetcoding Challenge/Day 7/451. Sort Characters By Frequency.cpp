class Solution {
public:
    string frequencySort(string s) {

        vector<pair<int,char>>vec;
        map<char,int>mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        for(auto i:mp){
            vec.push_back({i.second,i.first});
        }

        sort(vec.rbegin(),vec.rend());

        string res;
        
        for(auto i:vec){
            for(int j=0;j<i.first;j++){
                res+= i.second;
            }
        }
        return res;
    }
};
