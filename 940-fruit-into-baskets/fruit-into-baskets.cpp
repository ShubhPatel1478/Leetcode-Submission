class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0;
        int r=0;
        int maxi=0;
        unordered_map<int,int>freq;
        while(r<n){
             freq[fruits[r]]++;
             if(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0){
                    freq.erase(fruits[l]);
                }
                l++;
             }
             maxi=max(maxi,r-l+1);
             r++;
        }
        return maxi;
    }
};