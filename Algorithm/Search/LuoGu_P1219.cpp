#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> column_visited;
vector<bool> diagonal_visited;
vector<bool> anti_diagonal_visited;
vector<vector<int>> res;
void dfs(int row, int n, vector<int> path){
    if(row==n){
        res.push_back(path);
        return;
    }
    for(int i=0;i<n;i++){
        if(column_visited[i] || diagonal_visited[row+i] || anti_diagonal_visited[row-i+n-1]) continue;
        column_visited[i]=diagonal_visited[row+i]=anti_diagonal_visited[row-i+n-1]=true;
        path.push_back(i+1);
        dfs(row+1,n,path);
        path.pop_back();
        column_visited[i]=diagonal_visited[row+i]=anti_diagonal_visited[row-i+n-1]=false;
    }
}
int main(){
    int n; cin>>n;
    column_visited.resize(n, false);
    diagonal_visited.resize(2*n-1, false);
    anti_diagonal_visited.resize(2*n-1, false);
    dfs(0, n, {});
    for(int i=0;i<3;i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<res.size()<<endl;
    return 0;
}