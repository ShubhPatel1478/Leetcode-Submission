class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int product=1;
        int l=0;
        int r=0;
        while(r<n){
            product=product*nums[r];
            while(product>=k){
                product=product/nums[l];
                l++;
            }
            ans=ans+(r-l+1);
            r++;
        }
        return ans;
    }
};