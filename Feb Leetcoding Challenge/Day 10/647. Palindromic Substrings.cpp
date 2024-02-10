// TC - O(N^3)
// SC- O(1)

class Solution {
public:

    bool f(string s,int left,int right){
        while(left<right){
            if(s[left]!=s[right])
                return false;
                left++;
                right--;
            }         
            return true;  
    }

    int countSubstrings(string s) {
        int n = s.length();
        int res=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(s,i,j)) res++;
            }
        }
        return res;
    }
};



// TC - O(N^2)
// SC- O(N^2)

class Solution {
public:

    int f(string &s,int left,int right){
        int n = s.length();
        int count=0;

        while(left>=0 && right < n &&s[left]==s[right]){
            --left;
            ++right;
            ++count;
        }
        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int res=0;

        for(int i=0;i<n;++i){
            int even = f(s,i,i+1);
            int odd = f(s,i,i);

            res+= even+odd;
        }
        return res;
    }

    
};
