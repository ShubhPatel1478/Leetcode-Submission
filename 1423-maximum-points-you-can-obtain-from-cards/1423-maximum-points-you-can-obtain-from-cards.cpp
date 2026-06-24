class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        pre[0]=cardPoints[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+cardPoints[i];
        }
        suf[n-1]=cardPoints[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+cardPoints[i];
        }
        int maxi=INT_MIN;
        for(int i=0;i<=k;i++){
           int left=i;
           int right=k-i;
           int sum=0;
           if(left>0){
            sum=sum+pre[left-1];
           }
           if(right>0){
            sum=sum+suf[n-right];
           }
           maxi=max(maxi,sum);
        }
        return maxi;
    }
};