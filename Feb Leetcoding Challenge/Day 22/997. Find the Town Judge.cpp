class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> res(n+1,0);

        for(auto v:trust){
            res[v[0]]--;
            res[v[1]]++;
        }

        for(int i=1;i<=n;i++){
            if(res[i]==n-1)
            return i;
        }
        return -1;
    }
};
