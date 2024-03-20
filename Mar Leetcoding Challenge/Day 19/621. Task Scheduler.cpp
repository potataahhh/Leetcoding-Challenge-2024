class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        unordered_map<char, int> mp;
        
        for(char &ch : tasks) {
            mp[ch]++;
        }

        priority_queue<int> pq;                              //max heap
        int time = 0;
        
        for(auto &it : mp) {
            pq.push(it.second);
        }
        
        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 1; i<=n+1; i++) {
                                                            //filling first p+1 characters
                if(!pq.empty()) {
                    temp.push_back(pq.top()-1);             //finishing one instance of each process
                    pq.pop();
                }
            }
            
            for(int &freq : temp) {
                if(freq > 0)
                    pq.push(freq);
            }
            
            if(pq.empty())                          //all processes finished
                time += temp.size();
            else
                time += (n+1);                      //we finished p+1 tasks above in the loop
            
        }
        
        return time;
    }
};
