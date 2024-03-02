class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j = n-1;
        int k = n-1;
        vector<int> res(n);

        while(k>=0){
            int a = nums[i]*nums[i];
            int b = nums[j]*nums[j];

            if(a>b){
                res[k]=a;
                i++;
            }
            else{
                res[k]=b;
                j--;
            }
            k--;
        }
        return res;
    }
};
