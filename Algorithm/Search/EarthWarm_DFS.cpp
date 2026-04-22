#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<char>> mp;
vector<vector<bool>> visited;
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool flag;
void dfs(int x,int y){
    visited[x][y]=true;
    if(mp[x+1][y]=='#' && mp[x-1][y]=='#' && mp[x][y+1]=='#' && mp[x][y-1]=='#'){
        flag=true;
    }
    for(int i=0;i<4;i++){
        int nx=x+d[i][0],ny=y+d[i][1];
        if(!visited[nx][ny] && mp[nx][ny]=='#'){
            dfs(nx,ny);
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
                dfs(i,j);
                if(!flag) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}