
class Solution {
public:
    
    //This is just we are finding next smalong longer to each element to left
    //Similar 
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    //This is just we are finding next smaller to each element to right
    //Similar 
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //non-strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n); //Next smaller to left
        vector<int> NSR = getNSR(arr, n); //Next smaller to right
        
        
        long long sum = 0;
        int M = 1e9+7;
        for(int i = 0; i<n; i++) {
            long long d1 = i - NSL[i]; //distance to nearest smaller to left from i
            
            long long d2 = NSR[i] - i; //distance to nearest smaller to right from i
            
            /*
                we have d1 numbers in the left and d2 numbers in the right
                i.e. We have d1 options to start from the left of arr[i] 
                and d2 options to end in the right of arr[i]
                so the total options to start and end are d1*d2
            */
            long long total = d1*d2;
            long long totalSum  = arr[i] * (total);
            
            sum  = (sum + totalSum)%M;
        }
        
        return sum;
        
    }
};
