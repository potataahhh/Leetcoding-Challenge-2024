class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string res(n,'0');
        int i=0;

        for(char &ch : s){
            if(ch=='1'){
                if(res[n-1]=='1'){
                    res[i]='1';
                    i++;
                }
                else{
                    res[n-1]='1';
                }
            }
        }
        return res;
    }
};
