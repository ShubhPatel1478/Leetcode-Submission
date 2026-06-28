class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int i=nums.size()-1;
        while(i>=0 && k>0){
            if(mul>1){
            ans=ans+(1LL*nums[i]*mul);
            }
            else{
                ans=ans+nums[i];
            }
            mul--;
            k--;
            i--;
        }
        return ans;
    }
};