#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c;
vector<ll> w;
ll ans=0;
void dfs(int u,ll current_w){
    if(current_w>c) return;
    if(u==n || current_w==c){
        ans=max(ans,current_w);
        return;
    }
    dfs(u+1,current_w);
    if(current_w+w[u]<=c) dfs(u+1,current_w+w[u]);
}
int main(){
    cin>>n>>c;
    w.resize(n);
    for(int i=0;i<n;i++) cin>>w[i];
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}