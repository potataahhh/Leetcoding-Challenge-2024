class Solution {
public:

    int M = 1e9+7;

    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));


        //t[i][j] = total number of arrays having (1 to i) and exactly j inversions
        //for j = 0, t[i][0] = 1


        for(int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for(int i = 1; i <= n; i++) {
            long long res = 1;
            for(int j = 1; j <= k; j++) {
                
                res += t[i-1][j];
                if(j >= i) {
                    res -= t[i-1][j-i];
                }
                t[i][j] = res % M;
            }
        }


        return t[n][k];
        
    }
};
        
