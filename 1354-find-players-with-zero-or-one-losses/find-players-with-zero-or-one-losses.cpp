class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int maxi=1;
        for(int i=0;i<matches.size();i++){
            maxi=max(maxi,matches[i][0]);
            maxi=max(maxi,matches[i][1]);
        }
        vector<int>adj[maxi+1];
        vector<int>ind(maxi+1,0);
        for(int i=0;i<matches.size();i++){
             adj[matches[i][0]].push_back(matches[i][1]);
             ind[matches[i][0]]++;
             ind[matches[i][1]]++;
        }
        //ind will help us to find the total number of matches played by the element
        //size of the vector will help us to get the numebr of matches he has won
        vector<vector<int>>ans;
        vector<int>a1;
        vector<int>a2;
        for(int i=1;i<=maxi;i++){
            if(ind[i]>0 && ind[i]==adj[i].size()){
                a1.push_back(i);
            }
            if(ind[i]>0 && ind[i]==adj[i].size()+1){
                a2.push_back(i);
            }
        }
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};