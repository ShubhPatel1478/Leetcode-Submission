class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>nw,ww;
        int n=s.size();
        int m=p.size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            nw[p[i]]++;
        }
        int l=0;
        int r=0;
        while(r<n){
            ww[s[r]]++;
            while(r-l+1>m){
                ww[s[l]]--;
                if(ww[s[l]]==0){
                    ww.erase(s[l]);
                }
                l++;
            }
            if(r-l+1==m && ww==nw){
                ans.push_back(l);
            }
            r++;
        }
        return ans;
    }
};