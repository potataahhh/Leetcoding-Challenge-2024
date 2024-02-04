class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        unordered_map<char,int> mp;

        for(char &ch : t)
        mp[ch]++;

        int i=0,j=0,count=t.length(),sub_i=0,minWind =INT_MAX;

        while(j<n){
            char ch = s[j];

            if(mp[ch]>0)
            count--;
            mp[ch]--;

            while(count==0){
                int curr_win = j-i+1;

                while(curr_win < minWind){
                minWind= curr_win;
                sub_i =i;
                }

                mp[s[i]]++;

                if(mp[s[i]]>0){
                    count++;
                }
                i++;
            }
            j++;
        }
        return minWind == INT_MAX ? "" : s.substr(sub_i,minWind);
    }
};
