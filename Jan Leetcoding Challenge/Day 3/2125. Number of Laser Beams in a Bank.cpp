class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        // find total number of rows in bank
        int n = bank.size();

        // initiate prev with 0
        int prev=0;
        int res=0;
        for(int i=0;i<n;i++){
            int curr =0;

            // check through every element in the row
            for(char &ch: bank[i]){

                // if char is 1 , increment curr by 1
                if(ch=='1'){
                    curr++;
                }
            }

            // calcultae the laser by curr*prev
                res+= (curr*prev);

            // if curr row has no laser then prev == curr
                if(curr!=0){
                    prev = curr;
                }
        }
        return res;
    }
};
