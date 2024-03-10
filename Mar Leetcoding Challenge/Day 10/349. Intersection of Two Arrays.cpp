class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));

        vector<int> res;

        int n1=nums1.size();
        int n2=nums2.size();

        int i=0;
        int j=0;

        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
            
            while(i<n1-1 && nums1[i]==nums1[i+1]){
                i++;
            }
            while(j<n2-1 && nums2[j]==nums2[j+1]){
                j++;
            }
            i++;
            j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};
