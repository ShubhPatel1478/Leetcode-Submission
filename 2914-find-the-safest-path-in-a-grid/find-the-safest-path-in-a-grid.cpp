class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                   dis[i][j]=0;
                   q.push({i,j});
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                    if(1+dis[row][col]<dis[nrow][ncol]){
                    dis[nrow][ncol]=1+dis[row][col];
                    q.push({nrow,ncol});
                    }
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        pq.push({dis[0][0],{0,0}});
        while(!pq.empty()){
            int s=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==n-1){
                return s;
            }
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    int ns=min(s,dis[nrow][ncol]);
                    pq.push({ns,{nrow,ncol}});
                }
            }
        }
        return 0;
    }
};