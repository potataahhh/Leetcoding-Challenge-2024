class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        int mod = 1e9+7;
        vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        int t[50][50][51];
        memset(t,0,sizeof(t));

        for(int k=1;k<=maxMove;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    for(vector<int> &dir:directions){
                        int x=i+dir[0];
                        int y=j+dir[1];

                        if(x<0||x>=m||y<0||y>=n){
                            t[i][j][k]=(t[i][j][k]+1)%mod;
                        }
                        else{
                            t[i][j][k]=(t[i][j][k]+t[x][y][k-1])%mod;
                        }
                    }
                }
            }
        }

        return t[startRow][startColumn][maxMove];
    }
};
