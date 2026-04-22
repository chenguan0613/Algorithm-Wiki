#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<char>> mp;
vector<vector<bool>> visited;
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool flag;
void BFS(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        int tx=t.first,ty=t.second;
        if(mp[tx][ty+1]=='#' && mp[tx][ty-1]=='#' && mp[tx+1][ty]=='#' && mp[tx-1][ty]=='#'){
            flag=true;
        }
        for(int i=0;i<4;i++){
            int nx=tx+d[i][0],ny=ty+d[i][1];
            if(!visited[nx][ny] && mp[nx][ny]=='#'){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    int n; cin>>n;
    mp.resize(n+2,vector<char>(n+2,'.'));
    visited.resize(n+2,vector<bool>(n+2,false));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]=='#' & !visited[i][j]){
                flag=false;
                BFS(i,j);
                if(!flag) ans++;
            }
        }    }
    cout<<ans<<endl;
    return 0;
}