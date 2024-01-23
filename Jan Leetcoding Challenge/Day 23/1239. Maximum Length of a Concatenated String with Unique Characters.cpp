class Solution {
public:
    bool check(string &s1, string& s2) {
        int arr[26] = {0};
        
        for(char &ch : s1) {
            if(arr[ch-'a'] > 0)
                return true;
            arr[ch-'a']++;
        }
        
        for(char &ch : s2) {
            if(arr[ch-'a'] > 0)
                return true;
        }
        
        return false;
    }

    
    int solve(int i, vector<string>& arr, string temp, int n) {
        if(i >= n)
            return temp.length();
        
        int inc = 0;
        int exc = 0;
        if(check(arr[i], temp)) {
            exc = solve(i+1, arr, temp, n);
        } else {
            exc = solve(i+1, arr, temp, n);
            inc = solve(i+1, arr, temp+arr[i], n);
        }
        
        return max(inc, exc);
    }
    
    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        
        return solve(0, arr, temp, n);
        
    }
};
