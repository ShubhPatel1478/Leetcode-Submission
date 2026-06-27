class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long sum=0;
        long long ans=0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++)
        {
            sum+=nums[r];
            freq[nums[r]]++;
            while(freq[nums[r]]>1 || r-l+1>k)
            {
                freq[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            if(r-l+1==k)
                ans = max(ans, sum);
        }
        return ans;
    }
};