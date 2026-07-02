class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>best(n,vector<int>(m,-1));
        if(grid[0][0]){
            health--;
        }
        if(health<1){
            return false;
        }
        best[0][0]=health;
        queue<pair<int,pair<int,int>>>q;
        q.push({health,{0,0}});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            int heal=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(row==n-1 && col==m-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                int nhp=heal;
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m){
                    continue;
                }
                nhp=nhp-grid[nrow][ncol];
                if(nhp<=0){
                    continue;
                }
                if(nhp>best[nrow][ncol]){
                    best[nrow][ncol]=nhp;
                    q.push({nhp,{nrow,ncol}});
                }
            }
        }
        if(best[n-1][m-1]>=1){
            return true;
        }
        return false;
    }
};