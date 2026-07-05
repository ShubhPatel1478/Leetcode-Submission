class Solution {
public:
    int f(int n){
        vector<int>v;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        while(n>0){
            int r=n%10;
            maxi=max(maxi,r);
            mini=min(mini,r);
            n=n/10;
        }
        return maxi-mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxi=INT_MIN;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int k=f(nums[i]);
            if(k>maxi){
                maxi=k;
            }
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(f(nums[i])==maxi){
               sum=sum+nums[i];
            }
        }
        return sum;
    }
};