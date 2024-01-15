//create a unordered map to get the frequency of each player who lost 
// populate the unordered map with the lost frequency
// create 2 vecotr to store the element which either never lost or lost once 
// check for the element in the map and accordingly add it to the vectors 
// sort both vectors
// return the result

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int loser = matches[i][1];
            mp[loser]++;
        }

        vector<int> noLose;
        vector<int> lostOnce;

        for(int i=0;i<n;i++){
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(mp.find(winner)==mp.end()){
                noLose.push_back(winner);
                mp[winner]=2;
            }

            if(mp[loser]==1){
                lostOnce.push_back(loser);
            }
        }

        sort(begin(noLose),end(noLose));
        sort(begin(lostOnce),end(lostOnce));

        return {noLose,lostOnce};
    }
};
