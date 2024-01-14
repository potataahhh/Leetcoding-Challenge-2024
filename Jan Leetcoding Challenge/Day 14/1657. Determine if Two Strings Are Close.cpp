// check if the lenght of both string is same or not , if not return false
// create 2 vectors to store the freq of the elements 
// put the character from words one by one
// find the index of the character and fill it up in vector to check for frequency
// check if frq of character is same in both vector
// sort the freq vector
// check if frq1==frq2

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if(n!=m) return false;

        vector<int> frq1(26);
        vector<int> frq2(26);

        for(int i=0;i<n;i++){
            char ch1=word1[i];
            char ch2=word2[i];

            int ind1=ch1-'a';
            int ind2=ch2-'a';

            frq1[ind1]++;
            frq2[ind2]++;
        }

        for(int i=0;i<26;i++){
            if(frq1[i]!=0 && frq2[i]!=0) continue;
            if(frq1[i]==0 && frq2[i]==0) continue;
            return false;
        }

        sort(begin(frq1),end(frq1));
        sort(begin(frq2),end(frq2));

        return frq1==frq2;
    }
};
