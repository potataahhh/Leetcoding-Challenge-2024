// use a map to store the frequency of character of both the strings
// take the frequency of s tring in positive and t string in negative
// map the freq of both character and return the result

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        int res=0;
        unordered_map<char,int> freq;

        for(int i=0;i<n;i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(auto p: freq){
            if(p.second>0){
                res+=p.second;
            }
        }
        return res;
    }
};
