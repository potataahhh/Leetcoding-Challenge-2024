class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        int n = intervals.size();

        // answer vector
        vector<vector<int>> res;

        while(i<n){

            // if last digit of 1st interval is smaller than the first digit of new interval , pushback to vector 
            if(intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);
            }

            // if the starting element of the 1st interval is larger than the new interval than break the loop
            else if(intervals[i][0]>newInterval[1]){
                break;
            }
            else{

                // else merge the two interval . for that find the minimum of the first elements and the maximum of the last elements of the interval
                newInterval[0]= min(newInterval[0],intervals[i][0]);
                newInterval[1]= max(newInterval[1],intervals[i][1]);
            }
            i++;

        }

        // push the new interval into answer vector and then push the remaining elements in the vector too
        res.push_back(newInterval);
        while(i<n){
        res.push_back(intervals[i]);
        i++;
        }
        return res;
    }
};
