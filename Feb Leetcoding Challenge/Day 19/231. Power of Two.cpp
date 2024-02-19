class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;

        int count = __builtin_popcount(n);
        return count==1;
    }
};
