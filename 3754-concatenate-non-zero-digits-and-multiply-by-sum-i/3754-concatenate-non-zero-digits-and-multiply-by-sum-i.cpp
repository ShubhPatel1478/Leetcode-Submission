class Solution {
public:
    long long f(int n){
        long long ans=0;
        while(n>0){
            int r=n%10;
            ans=(ans*10)+r;
            n=n/10;
        }
        return ans;
    }
    long long sumAndMultiply(int n) {
        int sum=0;
        long long ans=0;
        while(n>0){
           int r=n%10;
           if(r>0){
            sum=sum+r;
            ans=(ans*10)+r;
           }
           n=n/10;
        }
        ans=f(ans);
        return ans*sum;
    }
};