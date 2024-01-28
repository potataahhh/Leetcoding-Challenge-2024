class Solution {
public:
    int getCount(vector<int> &prefix, int target){
        unordered_map<int,int> m;
        int sum = 0;
        int res = 0;
        m[0]=1;
        for(auto i : prefix){
            sum += i;
            if(m[sum-target] > 0){
                res += m[sum-target];
            }
            m[sum]++;
        }
        return res;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        
        for(int i=0;i<m; i++){
            vector<int> prefix(n, 0);
            for(int j=i; j<m; j++){
                for(int k=0;k<n;k++){
                    prefix[k] += matrix[j][k];
                }
                res += getCount(prefix, target);
            }
        }
        return res;
    }
};
