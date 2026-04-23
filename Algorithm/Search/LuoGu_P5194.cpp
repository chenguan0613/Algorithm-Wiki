#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c;
vector<ll> w;
vector<ll> pre_sum;
ll ans=0;
void dfs(int u,ll current_w){
    if(current_w>c) return;
    if(u<0 || current_w==c){
        ans=max(ans,current_w);
        return;
    }
    if(current_w+pre_sum[u+1]<=c){
        ans=max(ans,current_w+pre_sum[u+1]);
        return;
    }
    dfs(u-1,current_w);
    if(current_w+w[u]<=c){
        dfs(u-1,current_w+w[u]);
    }
}
int main(){
    cin>>n>>c;
    w.resize(n);
    pre_sum.resize(n+1);
    pre_sum[0]=0;
    for(int i=0;i<n;i++){
        cin>>w[i];
        pre_sum[i+1]=pre_sum[i]+w[i];
    }
    dfs(n-1,0);
    cout<<ans<<endl;
    return 0;
}