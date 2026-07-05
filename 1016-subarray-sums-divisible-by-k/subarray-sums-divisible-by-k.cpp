class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mpp;
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum%k==0){
                ans++;
            }
            int rem=((sum%k)+k)%k;
            if(mpp.find(rem)!=mpp.end()){
                ans=ans+mpp[rem];
            }
            mpp[rem]++;
        }
        return ans;
    }
};