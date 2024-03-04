class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int score=0;

        sort(tokens.begin(),tokens.end());
        int i=0;
        int j =n-1;
        int maxi =0;


        while(i<=j){
            if(power>= tokens[i]){
                power-=tokens[i];
                score++;
                maxi = score;
                i++;
            }
            else if(score>=1){
                power+=tokens[j];
                score--;
                j--;
            }
            else{
                return maxi;
            }
        }
        return maxi;
    }
};
