        // create a vector to store start point , end point and profit of 1 job.
        // store the elements into that array
        // sort the vector according to start point
        // create a function with parameters array and current index i
        // base condition
        // make taken and not taken cases
        // create a function with parameters ()arr,l,jobEnd) to aplly binary search for selecting next job
        // return the max of takena and notTaken
        // memoization


class Solution {
public:
    int n;
    int memo[50001];

    int nextJob(vector<vector<int>> &arr, int l , int JobEnd){
        int r = n-1;
        int res = n+1;

        while(l<=r){
            int mid = l+ (r-l)/2;

            if(arr[mid][0]>=JobEnd){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }

    int f(vector<vector<int>> &arr,int i){
        if(i>=n) return 0;
        if(memo[i]!=-1) return memo[i];

        int next = nextJob(arr,i+1,arr[i][1]);

        int taken = arr[i][2] + f(arr,next);
        int notTaken = f(arr,i+1);

        return memo[i] = max(taken,notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        

        n=startTime.size();
        memset(memo,-1,sizeof(memo));
        vector<vector<int>> arr(n,vector<int>(3,0));

        for(int i=0;i<n;i++){

            arr[i][0]= startTime[i];
            arr[i][1]= endTime[i];
            arr[i][2] = profit[i];

        }

        sort(arr.begin(),arr.end());

        return f(arr,0);

    }
};
