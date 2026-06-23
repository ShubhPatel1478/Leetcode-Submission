class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
           for(int j=0;j<friends[i].size();j++){
              adj[i].push_back(friends[i][j]);
           }
        }
        vector<int>vis(n,0);
        vis[id]=1;
        queue<pair<int,int>>q;
        vector<int>s;
        q.push({id,0});
        while(!q.empty()){
            int node=q.front().first;
            int l=q.front().second;
            q.pop();
            if(l==level){
                s.push_back(node);
            }
            for(int i=0;i<adj[node].size();i++){
                int adjnode=adj[node][i];
                if(!vis[adjnode]){
                    vis[adjnode]=1;
                    q.push({adjnode,l+1});
                }
            }
        }
        map<string,int>mpp;
        for(int i=0;i<s.size();i++){
            int node=s[i];
            for(int j=0;j<watchedVideos[node].size();j++){
                mpp[watchedVideos[node][j]]++;
            }
        }
        vector<pair<int,string>>v;
        for(auto it:mpp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        vector<string>ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};