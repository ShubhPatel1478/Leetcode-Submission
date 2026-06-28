class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        map<int,int>mpp;
        int sum=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int req=sum-goal;
            if(mpp.find(req)!=mpp.end()){
            ans=ans+mpp[req];
            }
            mpp[sum]++;
        }
        return ans;
    }
};