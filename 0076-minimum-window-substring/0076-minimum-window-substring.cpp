class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int c=0;
        int minlen=INT_MAX;
        map<char,int>mpp;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        int l=0;
        int r=0;
        int k=-1;
        while(r<n){
            if(mpp[s[r]]>0){
                c++;
            }
            mpp[s[r]]--;
            while(c==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    k=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    c--;
                }
                l++;
            }
            r++;
        }
        string ans="";
        if(k==-1){
            return ans;
        }
        for(int i=k;i<k+minlen;i++){
            ans=ans+s[i];
        }
        return ans;
    }
};