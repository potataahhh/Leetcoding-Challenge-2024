class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // we can also directly use g.size() and s.size() 
        int n = g.size();
        int m = s.size();

        // sort the array for applying greedy approach
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i=0, count =0;

        // traverse through arrays to
        for(int j=0;j<m;j++){

            // if there is only 1 child we increase the counter and compare the ith and jth element of both arrays 
            if(i<n && g[i]<=s[j]){
                count++;
                i++;
            }
        }
        return count;
    }
};
