// create a stack to keep the temp values and compare it with the current element
// lets take a vector to store the result i.e our number of days
// iterate from last of the array
// check if the stack is empty and the current element should be smaller than the top of the stack
// if not,  pop the top stack
// if the stack is empty return 0
// if not , calculate the index 
// push the number of days in stack
// return the resultant vector


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && temperatures[i]>= temperatures[st.top()]){
            st.pop();
        }
        if(st.empty()){
            res[i]=0;
        }
            else{
            res[i]=st.top()-i;    // number of days
            }
            st.push(i);
        }
        return res;
    }
};
