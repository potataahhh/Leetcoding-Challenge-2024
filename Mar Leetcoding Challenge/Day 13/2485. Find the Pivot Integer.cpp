class Solution {
public:
    int pivotInteger(int n) {
        int i=1;
        int j = n;
        int leftSum=1;
        int rightSum=n;

        while(i<j){
            if(leftSum<rightSum){
                i++;
                leftSum+=i;
            }
            else{
                j--;
                rightSum+=j;
            }
        }
        return leftSum==rightSum ? i:-1;
    }
};
