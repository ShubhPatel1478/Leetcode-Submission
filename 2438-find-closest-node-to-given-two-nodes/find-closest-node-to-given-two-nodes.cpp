class Solution {
public:
    vector<int>finddistance(int src,vector<int>adj[],int n){
        vector<int>dis(n,1e9);
        dis[src]=0;
        queue<pair<int,int>>q;
        q.push({0,src});
        while(!q.empty()){
            int dist=q.front().first;
            int node=q.front().second;
            q.pop();
            for(int j=0;j<adj[node].size();j++){
                int adjnode=adj[node][j];
                if(dist+1<dis[adjnode]){
                    dis[adjnode]=dist+1;
                    q.push({dist+1,adjnode});
                }
            }
        }
        return dis;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1){
            adj[i].push_back(edges[i]);
            }
        }
        vector<int>a=finddistance(node1,adj,n);
        vector<int>b=finddistance(node2,adj,n);
        int maxi=INT_MAX;
        int in=-1;
        for(int i=0;i<n;i++){
              if(a[i]!=1e9 && b[i]!=1e9){
                int cur=max(a[i],b[i]);
                if(cur<maxi){
                    maxi=cur;
                    in=i;
                }
              }
        }
        return in;
    }
};